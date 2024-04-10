#include<bits/stdc++.h>

using namespace std;

int n, x, f[202000], szf, g[202000], szg, p, a[202000];

int main(){
  cin>>n; 
  f[0]=g[0]=-2e9;
  for (int i=1;i<=n;++i) 
      cin>>a[i],a[i]-=i+(1e9);
  for (int i=2;i<=n;++i){
    p=upper_bound(g,g+szg+1,a[i]+1)-g;
    szg=max(szg,p); g[p]=a[i]+1;
    p=upper_bound(f,f+szf+1,a[i-1])-f;
    szf=max(szf,p); f[p]=a[i-1]; g[p]=min(g[p],f[p]);
  }
  cout<<n-1-max(szg,szf);
}