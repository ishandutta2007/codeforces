#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const int MAX = 5e5 + 100;
int as[MAX],bs[MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>as[i];

  int ans=0;
  const int LOG = 27;
  for(int k=0;k<LOG;k++){
    int m=1<<k;
    for(int i=0;i<n;i++) bs[i]=as[i]&(m*2-1);
    sort(bs,bs+n);
    int cnt=0;
    for(int i=0;i+1<n;i++){
      int x=lower_bound(bs+i+1,bs+n,1*m-bs[i])-bs;
      int y=lower_bound(bs+i+1,bs+n,2*m-bs[i])-bs;
      int p=lower_bound(bs+i+1,bs+n,3*m-bs[i])-bs;
      int q=lower_bound(bs+i+1,bs+n,4*m-bs[i])-bs;
      cnt+=(y-x)+(q-p);
      cnt&=1;
    }
    if(cnt) ans+=m;
  }

  cout<<ans<<endl;
  return 0;
}