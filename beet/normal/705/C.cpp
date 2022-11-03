#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n,q;
  vector<P> v;
  int l[300005];
  memset(l,-1,sizeof(l));
  int c[300005]={};
  P p;
  cin >> n >> q;
  int i,j,k,x,s=0;
  int ans = 0;
  for(i=0;i<q;i++){
    cin >> j >> k;
    if(j==1){
      v.push_back(P(i,k));
      c[k]++;
      ans++;
    }else if(j==2){
      l[k]=i;
      ans-=c[k];
      c[k]=0;
    }else{
      for(x=s;x<k;x++){
	if(v[x].first>l[v[x].second]){
	  ans--;
	  c[v[x].second]--;
	}
      }
      s=max(s,k);
    }
    cout << ans << endl;
  }
  return 0;
}