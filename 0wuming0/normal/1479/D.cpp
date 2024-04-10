#include"bits/stdc++.h"
using namespace std;
struct qus
{
    int u,v,l,r;
    int pos;
    int lca;
}q[300005];
int ans[300005];
bool cmp(qus x,qus y)
{
    return x.u<y.u;
}
bool cmp2(qus x,qus y)
{
    return x.v<y.v;
}
bool cmp3(qus x,qus y)
{
    return x.v>y.v;
}
int save[600005],nn;
int pos[300005];
int a[300005];
vector<int>v[300005];
int vis[300005];
int fa[21][300005],s2[300005],dn;
int deep[300005];
void solve(int i)
{
    for(int k=0,cnt=1;cnt<=dn;k++,cnt<<=1)
    {
        fa[k][i]=s2[dn-cnt];
    }
    s2[dn++]=i;
    deep[i]=dn;
    vis[i]=1;
    save[nn]=i;
    pos[i]=nn++;
    for(auto j:v[i])if(vis[j]==0)
    {
        solve(j);
    }
    dn--;
    save[nn++]=i;
}
int lca(int a,int b)
{
    if(deep[a]<deep[b])swap(a,b);
    while(deep[a]!=deep[b])
    {
        int k=0;
        while(deep[fa[k][a]]>deep[b])
        {
            k++;
        }
        if(deep[fa[k][a]]<deep[b])k--;
        a=fa[k][a];
    }
    while(a!=b)
    {

        int k=0;
        if(fa[0][a]!=fa[0][b])
        {
            while(fa[k][a]!=fa[k][b])k++;
            k--;
        }
        a=fa[k][a];
        b=fa[k][b];
    }
    return a;
}
bool opt[604005];
int oknum[805];
int room[604005];
void moves(int &p,int aim)
{
    if(p<aim)
    {
        while(p!=aim)
        {
            //ers(p);
            p++;
            //add(p);
            {
                int &c=a[save[p]];
                if(opt[c])
                {
                    oknum[room[c]]--;
                    opt[c]=false;
                }
                else
                {
                    oknum[room[c]]++;
                    opt[c]=true;
                }
            }
        }
    }
    else if(p>aim)
    {
        while(p!=aim)
        {
            {
                int &c=a[save[p]];
                if(opt[c])
                {
                    oknum[room[c]]--;
                    opt[c]=false;
                }
                else
                {
                    oknum[room[c]]++;
                    opt[c]=true;
                }
            }
            //ers(p);
            p--;
            //add(p);
        }
    }
}
int main()
{
    for(int i=0,cnt=0,now=0;i<=604000;i++,cnt++)
    {
        if(cnt==550)
        {
            cnt=0;
            now++;
        }
        room[i]=now;
    }
    //cout<<550*300000<<endl;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&q[i].u,&q[i].v,&q[i].l,&q[i].r);
        q[i].lca=lca(q[i].u,q[i].v);
        q[i].u=pos[q[i].u];
        q[i].v=pos[q[i].v];
        q[i].pos=i;
        if(q[i].u>q[i].v)swap(q[i].u,q[i].v);
    }
    sort(q,q+m,cmp);
    for(int i=1,last=0;;i++)
    {
        static bool flag=true;
        if(i==m)
        {
            if(flag)sort(q+last,q+m,cmp2);
            else sort(q+last,q+m,cmp3);
            break;
        }
        else
        {
            if(room[q[i].u]!=room[q[i-1].u])
            {
                if(flag)sort(q+last,q+i,cmp2);
                else sort(q+last,q+i,cmp3);
                flag^=1;
                last=i;
            }
        }
    }
    int l=0,r=0;
    for(int i=0,cnt=0,now=0;i<=300000;i++,cnt++)
    {
        if(cnt==550)
        {
            cnt=0;
            now++;
        }
        room[i]=now;
    }
    room[0]=-1;
    room[300001]=-1;
    for(int i=0;i<m;i++)
    {
        moves(l,q[i].u);
        moves(r,q[i].v);
        {
            int &c=a[q[i].lca];
            if(opt[c])
            {
                oknum[room[c]]--;
                opt[c]=false;
            }
            else
            {
                oknum[room[c]]++;
                opt[c]=true;
            }
        }//cout<<"<<"<<q[i].u<<" "<<q[i].v<<" "<<save[q[i].u]<<" "<<save[q[i].v]<<" "<<q[i].l<<" "<<q[i].r<<" "<<q[i].pos<<endl;for(int i=1;i<=m;i++)cout<<opt[i];cout<<endl;
        ans[q[i].pos]=-1;
        if(room[q[i].l]==room[q[i].r])
        {
            for(int j=q[i].l;j<=q[i].r;j++)if(opt[j])
            {
                ans[q[i].pos]=j;
                break;
            }
        }
        else
        {
            for(int j=room[q[i].l]+1;j<room[q[i].r];j++)
            {
                if(oknum[j])
                {
                    int temp=550*j;
                    for(int k=temp;room[temp]==room[k];k++)if(opt[k])
                    {
                        ans[q[i].pos]=k;
                        break;
                    }
                    break;
                }
            }
            if(ans[q[i].pos]==-1)
            {
                for(int j=q[i].l;room[q[i].l]==room[j];j++)if(opt[j])
                {
                    ans[q[i].pos]=j;
                    break;
                }
            }
            if(ans[q[i].pos]==-1)
            {
                for(int j=q[i].r;room[q[i].r]==room[j];j--)if(opt[j])
                {
                    ans[q[i].pos]=j;
                    break;
                }
            }
        }
        {
            int &c=a[q[i].lca];
            if(opt[c])
            {
                oknum[room[c]]--;
                opt[c]=false;
            }
            else
            {
                oknum[room[c]]++;
                opt[c]=true;
            }
        }
    }
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    return 0;
}