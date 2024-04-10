#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000010;

char str[Maxn];

int main()
{
  
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("\n%c",&str[i]);
  for(int i=1;i<=m;i++)
  {
    int l,r;  char c1,c2;
    scanf("%d%d\n%c\n%c",&l,&r,&c1,&c2);
    for(int j=l;j<=r;j++) if(str[j]==c1) str[j]=c2;
  }
  for(int i=1;i<=n;i++) cout<<str[i] ; cout<<endl;
  return 0;
}