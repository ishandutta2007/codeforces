#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const int maxn=1e5+10,siz=320;

struct compressed_edge
{
    int v,lazy,total;
    vector<int> compressed_path,group_path,group_size;

    void clear_path()
    {
        lazy=total=0;
        for (int i=0;i<(int)group_path.size();i++) group_path[i]=0;
    }

    bool full()
    {
        if (total==(int)compressed_path.size()) return true;
        total++;
        lazy++;
        return false;
    }

    void down()
    {
        for (int i=0;i<(int)group_path.size() && lazy;i++)
            if (group_size[i]-group_path[i]<=lazy)
            {
                lazy-=group_size[i]-group_path[i];
                group_path[i]=group_size[i];
            }
            else
            {
                group_path[i]+=lazy;
                for (int j=i*siz;j<min(i*siz+siz,(int)compressed_path.size()) && lazy;j++)
                    if (!compressed_path[j]) compressed_path[j]=1,lazy--;
            }
    }

    void update(int gx)
    {
        if (group_path[gx]==group_size[gx])
            for (int i=gx*siz;i<gx*siz+group_size[gx];i++) compressed_path[i]=1;
        else if (!group_path[gx])
            for (int i=gx*siz;i<gx*siz+group_size[gx];i++) compressed_path[i]=0;
    }

    bool add(int x)
    {
        down();
        int gx=x/siz;
        update(gx);
        for (int i=x;i<min(gx*siz+siz,(int)compressed_path.size());i++)
            if (!compressed_path[i])
            {
                total++;
                compressed_path[i]=1;
                group_path[gx]++;
                return true;
            }
        for (int i=gx+1;i<(int)group_path.size();i++)
            if (group_path[i]<group_size[i])
            {
                group_path[i]++;
                total++;
                update(i);
                for (int j=i*siz;j<i*siz+siz;j++)
                    if (!compressed_path[j])
                    {
                        compressed_path[j]=1;
                        return true;
                    }
            }
        return false;
    }

    void clear_from(int x)
    {
        down();
        int gx=x/siz;
        update(gx);
        for (int i=x;i<min(gx*siz+siz,(int)compressed_path.size());i++)
            if (compressed_path[i])
            {
                total--;
                compressed_path[i]=0;
                group_path[gx]--;
            }
        for (int i=gx+1;i<(int)group_path.size();i++)
        {
            total-=group_path[i];
            group_path[i]=0;
        }
    }

    int access(int x)
    {
        down();
        update(x/siz);
        return compressed_path[x];
    }
};

int p[maxn],sl[maxn],vt[maxn],n,root[maxn],color[maxn],q;
vector<int> G[maxn],leaf_child[maxn],group_leaf[maxn];
vector<compressed_edge> CG[maxn];
pii belong[maxn];

void read()
{
    cin>>n>>q;
    for (int i=2;i<=n;i++) cin>>p[i];
}

void dfs_compressed(int u)
{
    for (int i=0;i<(int)G[u].size();i++)
    {
        int v=G[u][i];
        vector<int> cp,gp,gs;
        while (G[v].size()==1 && leaf_child[v].empty())
        {
            vt[v]=cp.size();
            cp.pb(0);
            if (cp.size()%siz==1) gp.pb(0),gs.pb(1);
            else gs.back()++;
            belong[v]=mp(u,CG[u].size());
            v=G[v][0];
        }
        compressed_edge tmp={v,0,0,cp,gp,gs};
        CG[u].pb(tmp);
        dfs_compressed(v);
    }
}

void build()
{
    for (int i=1;i<=n;i++) sl[i]=1;
    for (int i=n;i>1;i--) sl[p[i]]+=sl[i];
    for (int i=2;i<=n;i++)
        if ((sl[p[i]]<=siz && sl[i]<=siz) || (sl[p[i]]>siz && sl[i]>siz)) G[p[i]].pb(i);
        else
        {
            leaf_child[p[i]].pb(0);
            if (leaf_child[p[i]].size()%siz==1) group_leaf[p[i]].pb(0);
            vt[i]=leaf_child[p[i]].size()-1;
            root[i]=i;
        }
    dfs_compressed(1);
    for (int i=1;i<=n;i++)
        if (!root[i]) root[i]=root[p[i]];
}

void updateCG1(int u)
{
    if (!color[u])
    {
        color[u]=1;
        return;
    }
    for (int i=0;i<(int)CG[u].size();i++)
        if (CG[u][i].full()) updateCG1(CG[u][i].v);
    for (int i=0;i<(int)group_leaf[u].size();i++)
        if (group_leaf[u][i]<0) group_leaf[u][i]--;
        else group_leaf[u][i]++;
}

void updateG1(int u,int val)
{
    if (!val) return;
    if (!color[u]) val--;
    color[u]=1;
    for (int i=0;i<(int)G[u].size();i++) updateG1(G[u][i],val);
}

void updateCG2(int u)
{
    color[u]=0;
    for (int i=0;i<(int)CG[u].size();i++)
    {
        CG[u][i].clear_path();
        updateCG2(CG[u][i].v);
    }
    for (int i=0;i<(int)group_leaf[u].size();i++) group_leaf[u][i]=-1;
}

void updateG2(int u)
{
    color[u]=0;
    for (int i=0;i<(int)G[u].size();i++) updateG2(G[u][i]);
}

int access_leaf(int u,int x)
{
    int gx=x/siz;
    for (int i=gx*siz;i<min((int)leaf_child[u].size(),gx*siz+siz);i++)
        if (group_leaf[u][gx]<0) leaf_child[u][i]=group_leaf[u][gx];
        else if (leaf_child[u][i]<0) leaf_child[u][i]-=group_leaf[u][gx];
        else leaf_child[u][i]+=group_leaf[u][gx];
    group_leaf[u][gx]=0;
    int tmp=leaf_child[u][x];
    leaf_child[u][x]=0;
    return tmp;
}

int updateG(int u,int type)
{
    int r=root[u],val=access_leaf(p[r],vt[r]);
    if (val<0)
    {
        updateG2(r);
        val=-1-val;
    }
    updateG1(r,val);
    if (type==1) updateG1(u,1);
    else if (type==2) updateG2(u);
    else return color[u];
    return 0;
}

void query1(int u)
{
    if (root[u]) updateG(u,1);
    else if (belong[u].fi) CG[belong[u].fi][belong[u].se].add(vt[u]);
    else updateCG1(u);
}

void query2(int u)
{
    if (root[u]) updateG(u,2);
    else if (belong[u].fi) CG[belong[u].fi][belong[u].se].clear_from(vt[u]);
    else updateCG2(u);
}

int query3(int u)
{
    if (root[u]) return updateG(u,3);
    else if (belong[u].fi) return CG[belong[u].fi][belong[u].se].access(vt[u]);
    else return color[u];
}

void process()
{
    int t,x;
    for (int i=1;i<=q;i++)
    {
        cin>>t>>x;
        if (t==1) query1(x);
        else if (t==2) query2(x);
        else if (query3(x)) printf("black\n");
        else printf("white\n");
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    build();
    process();
    return 0;
}