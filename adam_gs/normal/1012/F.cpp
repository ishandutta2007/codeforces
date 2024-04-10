#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
const int N=22;
int dp[1<<N], jaki[1<<N], gdzie[1<<N], n;
pair<pair<int,int>,pair<int,int>>T[N];
pair<int,int>ans[N];
int nxt(int m, int x, int t) {
  int l=0;
  while(l<n && (x>=T[l].st.st || !(m&(1<<l)))) ++l;
  if(x<T[0].st.st && (l==n || x+t<T[l].st.st)) return x+t;
  rep(i, n) {
    if(T[i].st.nd>x) x=T[i].st.nd;
    if(i<n-1 && x>=T[i+1].st.st) continue;
    while(l<n && (x>=T[l].st.st || !(m&(1<<l)))) ++l;
    if(l==n || x+t<T[l].st.st) return min((long long)x+(long long)t, (long long)INF);;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int P;
  cin >> n >> P;
  rep(i, n) {
    cin >> T[i].st.st >> T[i].st.nd >> T[i].nd.st;
    T[i].st.nd+=T[i].st.st;
    T[i].nd.nd=i;
    if(T[i].st.st==1) {
      cout << "NO\n";
      return 0;
    }
  }
  sort(T, T+n);
  dp[0]=1;
  for(int i=1; i<(1<<n); ++i) {
    dp[i]=INF;
    rep(j, n) if(i&(1<<j)) {
      ll x=nxt(i, dp[i^(1<<j)], T[j].nd.st);
      if(x>=T[j].st.st) x=INF;
      if(dp[i]>x) {
        dp[i]=x;
        jaki[i]=j;
        gdzie[i]=x-T[j].nd.st;
      }
    }
  }
  rep(i, 1<<n) if((i==(1<<n)-1 || P==2) && max(dp[i], dp[((1<<n)-1)^i])<INF) {
    int x=i;
    while(x) {
      ans[T[jaki[x]].nd.nd]={1, gdzie[x]};
      x-=1<<jaki[x];
    }
    x=((1<<n)-1)^i;
    while(x) {
      ans[T[jaki[x]].nd.nd]={2, gdzie[x]};
      x-=1<<jaki[x];
    }
    cout << "YES\n";
    rep(i, n) cout << ans[i].st << " " << ans[i].nd << '\n';
    return 0;
  }
  cout << "NO\n";
}