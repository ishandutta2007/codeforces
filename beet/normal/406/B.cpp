#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1111111];
bool used[1111111];
signed main(){
  int s=1000000;
  int n;
  scanf("%lld",&n);
  for(int i=0;i<n;i++) scanf("%lld",x+i);
  int sum=0;
  int res=0;
  for(int i=0;i<n;i++) sum+=n-x[i];
  for(int i=0;i<n;i++) used[x[i]]=1;
  for(int i=1;i<=s;i++) if(!used[i]) res+=n-i;
  vector<int> ans;
  vector<int> unused;
  int r=0;
  for(int i=1;i<=s/2;i++){
    if(used[i]&used[s+1-i]) r++;
    else if(!used[i]&!used[s+1-i]) unused.push_back(i);
    else if(used[i]) ans.push_back(s+1-i);
    else ans.push_back(i);
  }
  for(int i=0;i<r;i++){
    ans.push_back(unused[i]);
    ans.push_back(s+1-unused[i]);
  }
  sort(ans.begin(),ans.end());
  printf("%lld\n",(int)ans.size());
  for(int i=0;i<(int)ans.size();i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}