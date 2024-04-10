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
  int n,k;
  cin>>n>>k;
  string a;
  cin>>a;

  auto form=[&](string s){
    string ans(n,'.');
    for(int i=0;i<n;i++)
      ans[i]=s[i%k];
    return ans;
  };

  auto inc=[&](string s){
    int m=s.size();
    for(int i=m-1;i>=0;i--){
      if(s[i]=='9'){
        s[i]='0';
        continue;
      }
      s[i]++;
      break;
    }
    return s;
  };

  cout<<n<<endl;
  string b=a.substr(0,k);
  for(int i=0;i<n;i++){
    if(a[i]==b[i%k]) continue;
    if(a[i]< b[i%k]) drop(form(b));
    drop(form(inc(b)));
  }
  cout<<a<<endl;
  return 0;
}