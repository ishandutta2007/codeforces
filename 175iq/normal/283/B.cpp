#include<iostream>
 
using namespace std;
const int N=2*1e5;
long long a[N], y[2][N];
int n;
long long fun(int i, int x)
{
  if (x<=0||x>n) return 0;
  if (y[i][x]!=0){return y[i][x];}
  y[i][x]=-1;
  long long r;
  if (i==1)r=fun(0,x+a[x]);
    else r=fun(1,x-a[x]);
    if (r==-1) return -1;
    y[i][x]=a[x]+r;
    return y[i][x];
}
int main()
{
  cin>>n;
  for (int i=2;i<=n;i++) cin>>a[i];
  for (int i=1;i<n;i++)
  {
     a[1]=i;
     y[1][1] = 0;
     cout<<fun(1,1)<<endl;
  }
  return 0;
}