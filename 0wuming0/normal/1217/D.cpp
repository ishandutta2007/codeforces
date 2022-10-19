#include"bits/stdc++.h"
using namespace std;
int ans[5006];
struct road
{
    int num;
    int pos;
};
vector<road>v[5006];
int vis[5006];
int sortnum[5006];
int nn;
void solve(int i)
{
    for(vector<road>::iterator it=v[i].begin();it!=v[i].end();++it)
    {
        sortnum[it->pos]--;
        if(sortnum[it->pos]==0)
        {
            nn++;
            vis[it->pos]=1;
            solve(it->pos);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        road t;
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b)ans[i]=1;
        else ans[i]=2;
        t.pos=b;
        t.num=i;
        v[a].push_back(t);
        sortnum[b]++;
        /*
        t.pos=a;
        v[b].push_back(t);*/
    }
    //for(int i=1;i<=n;i++)cout<<"!!"<<sortnum[i]<<endl;
    for(int i=1;i<=n;i++)if(sortnum[i]==0)
    {//cout<<"?"<<i<<" "<<nn<<endl;
        nn++;
        vis[i]=1;
        solve(i);
    }//cout<<n<<" "<<nn<<endl;
    nn=0;
    for(int i=1;i<=n;i++)nn+=vis[i];//cout<<"!!"<<vis[i]<<endl;
    for(int i=1;i<=n;i++)if(n==nn)
    {
        cout<<1<<endl;
        for(int j=0;j<m;j++)printf("%d%c",1," \n"[j==m-1]);
        return 0;
    }
    cout<<2<<endl;
    for(int i=0;i<=n;i++)vis[i]=0;
    //for(int i=1;i<=n;i++)if(!vis[i])solve(i);
    for(int j=1;j<=m;j++)printf("%d%c",ans[j]," \n"[j==m]);
    return 0;
}
/*
4 2
1 2
2 1

3 3
1 2
2 3
3 1
*/