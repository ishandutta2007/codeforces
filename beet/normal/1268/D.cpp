#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto ss=read<string>(n);

  vector<int> outdeg(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(ss[i][j]=='1') outdeg[i]++;

  auto check=[&](auto vs){
    sort(vs.begin(),vs.end());
    int sum=0;
    for(int i=0;i+1<n;i++){
      sum+=vs[i]-i;
      if(sum==0) return false;
    }
    return true;
  };

  if(check(outdeg)) drop("0 1");

  int num=0;
  for(int i=0;i<n;i++){
    vector<int> cur(outdeg);
    for(int j=0;j<n;j++){
      if(i==j) continue;
      if(ss[i][j]=='0') cur[i]++,cur[j]--;
      if(ss[i][j]=='1') cur[i]--,cur[j]++;
    }
    if(check(cur)) num++;
  }

  if(num){
    cout<<1<<' '<<num<<newl;
    return 0;
  }

  if(n==4) drop(-1);
  if(n==6) drop("2 18");

  abort();
  return 0;
}