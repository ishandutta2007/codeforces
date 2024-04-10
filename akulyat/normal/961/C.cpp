#include <bits/stdc++.h>

using namespace std;

long long n,u,i,j;
long long p[10][1000][1000];
long long a[10],b[10];



int main()
{
cin>>n;

for (u=0; u<4; u++)
  {
  for (i=0; i<n; i++)
    {
    string s;
    cin>>s;
    for (j=0; j<n; j++)
      {
      p[u][i][j]=(s[j]-'0');
      long long k=i+j;
      k&=1;
      if (p[u][i][j]==0)
        if (k==0)
          a[u]++;
        else
          b[u]++;
      if (p[u][i][j]==1)
        if (k==0)
          b[u]++;
        else
          a[u]++;
//      cout<<k<<' '<<p[u][i][j]<<endl;
      }
    }
//  cout<<a[u]<<' '<<b[u]<<endl;
  }

long long ans=4*n*n;
ans=min(ans, a[0]+a[1]+b[2]+b[3]);
ans=min(ans, a[0]+a[2]+b[1]+b[3]);
ans=min(ans, a[0]+a[3]+b[1]+b[2]);
ans=min(ans, a[1]+a[2]+b[0]+b[3]);
ans=min(ans, a[1]+a[3]+b[0]+b[2]);
ans=min(ans, a[2]+a[3]+b[0]+b[1]);

cout<<ans;


    return 0;
}