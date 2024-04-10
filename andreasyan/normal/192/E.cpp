#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > graph;

int n;
vector<int> dfs_list;
vector<int> rib_list;
vector<int> h;

void dfs(const graph& a,const graph& rib_ind,int x,int p,int th)
{
    h[x]=th;
    dfs_list.push_back(x);
    for(int i=0;i<a[x].size();++i)
    {
        int t=a[x][i];
        if(t==p)
            continue;
        rib_list.push_back(rib_ind[x][i]);
        dfs(a,rib_ind,t,x,th+1);
        rib_list.push_back(rib_ind[x][i]);
        dfs_list.push_back(x);
    }
}

//////////////////////////////L///////////////////C//////////////A///////////

vector<int> lca_tree;
int lca_mer(int l,int r)
{
    if(h[l]<h[r])
        return l;
    else
        return r;
}

void lca_bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        lca_tree[pos]=dfs_list[tl];
        return;
    }
    int m=(tl+tr)/2;
    lca_bil(tl,m,pos*2);
    lca_bil(m+1,tr,pos*2+1);
    lca_tree[pos]=lca_mer(lca_tree[pos*2],lca_tree[pos*2+1]);
}

vector<int> first;
void lca_pre()
{
    lca_tree.assign(dfs_list.size()*4+1,-1);
    lca_bil(0,dfs_list.size()-1,1);

    first.assign(n+1,-1);
    for(int i=0;i<dfs_list.size();++i)
    {
        if(first[dfs_list[i]]==-1)
            first[dfs_list[i]]=i;
    }
}

int lca_qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return lca_tree[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return lca_qry(tl,m,l,r,pos*2);
    else if(l>m)
        return lca_qry(m+1,tr,l,r,pos*2+1);
    else
    {
        return lca_mer(lca_qry(tl,m,l,m,pos*2),lca_qry(m+1,tr,m+1,r,pos*2+1));
    }
}

int lca(int x,int y)
{
    if(first[x]>first[y])
        swap(x,y);
    return lca_qry(0,dfs_list.size()-1,first[x],first[y],1);
}

//////////////////Q////////////////////R/////////////////Y////////////////

vector<int> t;
vector<int> first1,first2;
void qry_pre()
{
    first1.assign(n+1,-1);
    first2.assign(n+1,-1);
    for(int i=0;i<rib_list.size();++i)
    {
        int k=rib_list[i];
        if(first1[k]==-1)
            first1[k]=i;
        else
            first2[k]=i;
    }

    t.assign(rib_list.size()*4+5,0);
}

void tree_ubd(vector<int>& t,int tl,int tr,int l,int r,int pos)
{
    if(l>r)
        return;
    if(tl==l && tr==r)
    {
        t[pos]++;
        return;
    }
    int m=(tl+tr)/2;
    if(r<=m)
        tree_ubd(t,tl,m,l,r,pos*2);
    else if(l>m)
        tree_ubd(t,m+1,tr,l,r,pos*2+1);
    else
    {
        tree_ubd(t,tl,m,l,m,pos*2);
        tree_ubd(t,m+1,tr,m+1,r,pos*2+1);
    }
}

int tree_qry(vector<int>& t,int tl,int tr,int x,int pos)
{
    if(tl==tr)
        return t[pos];
    int m=(tl+tr)/2;
    if(x<=m)
        return t[pos]+tree_qry(t,tl,m,x,pos*2);
    else
        return t[pos]+tree_qry(t,m+1,tr,x,pos*2+1);
}

void ubd(int x,int y)
{
    int l=lca(x,y);
    //////xxxxxxxxxxxxxxxxxxxx
    tree_ubd(t,0,rib_list.size()-1,first[l],first[x]-1,1);
    //////yyyyyyyyyyyyyyyyyyyy
    tree_ubd(t,0,rib_list.size()-1,first[l],first[y]-1,1);
}

int qry(int i)
{
    return tree_qry(t,0,rib_list.size()-1,first1[i],1)-tree_qry(t,0,rib_list.size()-1,first2[i],1);
}
//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    graph a(n+1),rib_ind(n+1);
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        rib_ind[x].push_back(i);
        rib_ind[y].push_back(i);
    }

    h.assign(n+1,0);
    dfs(a,rib_ind,1,-1,0);
    lca_pre();
    qry_pre();

    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ubd(x,y);
    }

    for(int i=0;i<n-1;++i)
    {
        cout<<qry(i)<<' ';
    }
    cout<<endl;
    return 0;
}