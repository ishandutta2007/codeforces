#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[114514],b[114514],ans[114514];
int n,d,x;
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
  for(int i = 0; i < n; i = i + 1){
    a[i] = i + 1;
  }
  for(int i = 0; i < n; i = i + 1){
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for(int i = 0; i < n; i = i + 1){
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for(int i = 0; i < n; i = i + 1){
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
#define BS 500
signed main(){
  cin>>n>>d>>x;
  initAB();
  memset(ans,0,sizeof(ans));
  if(d<BS){
    for(int i=0;i<n;i++){
      if(!b[i]) continue;
      for(int j=0;i+j<n;j++)
	ans[i+j]=max(ans[i+j],a[j]);
    }
  }else{
    vector<int> v;
    map<int,int> m;
    for(int i=0;i<n;i++){
      m[a[i]]=i;
      if(b[i]) v.push_back(i);
      if((int)v.size()<BS){
	for(int j=0;j<(int)v.size();j++)
	  ans[i]=max(ans[i],a[i-v[j]]);
      }else{
	auto it=m.end();
	--it;
	while(!ans[i]){
	  if(b[i-(it->second)]){
	    ans[i]=it->first;
	    break;
	  }
	  if(it==m.begin()) break;
	  --it;
	}
      }
    }
  }
  for(int i=0;i<n;i++) printf("%lld\n",ans[i]);
  return 0;
}