#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];

  if(k==1){
    cout<<n<<endl;
    return 0;
  }
  sort(a,a+n);
  map<int,int> s;
  bool used[n];
  memset(used,0,sizeof(used));
  for(int i=0;i<n;i++) s[a[i]]=i;
  int ans=0;
  for(int i=0;i<n;i++){
    if(used[i]) continue;
    if(s.count(k*a[i])){
      int tmp=a[i],res=1;
      used[s[tmp]]=1;
      while(s.count(tmp*k)){
	tmp*=k;
	res++;
	used[s[tmp]]=1;
      }
      ans+=(res+1)/2;
    }else ans++;
  }
  cout<<ans<<endl;
  return 0;
}