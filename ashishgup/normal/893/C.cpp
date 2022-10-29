#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], root[N], size[N];
vector<int> g[N];

void preprocess()
{
   for(int i=1;i<N;i++)
   {
      root[i]=i;
      size[i]=1;
   }
}

int rt(int k)
{
   while(k!=root[k])
   {
      root[k]=root[root[k]];
      k=root[k];
   }
   return k;
}

void union1(int u, int v)
{
   int rtA=rt(u);
   int rtB=rt(v);
   if(size[rtA]>=size[rtB])
   {
      size[rtA]+=size[rtB];
      size[rtB]=0;
      root[rtB]=root[rtA];
   }
   else
   {
      size[rtB]+=size[rtA];
      size[rtA]=0;
      root[rtA]=root[rtB];
   }
}

int32_t main()
{
   IOS;
   preprocess();
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   for(int i=1;i<=m;i++)
   {
      int u, v;
      cin>>u>>v;
      union1(u, v);
   }
   for(int i=1;i<=n;i++)
   {
      g[rt(i)].push_back(a[i]);
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
      int curmin=1e9+1;
      for(auto it:g[i])
      {
         curmin=min(curmin, it);
      }
      if(curmin<=1e9)
      {
         ans+=curmin;
      }
   }
   cout<<ans;
}