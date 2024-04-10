#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int T[LIM], S[LIM], P[LIM], DO[LIM], jaki[LIM], odw[LIM], F[LIM];
map<int,int>mp;
vector<pair<int,int>>V;
vector<vector<int>>ans;
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
  if(fnd(a)==fnd(b)) return false;
  F[fnd(b)]=fnd(a);
  return true;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, s;
  cin >> n >> s;
  rep(i, n) {
    cin >> T[i];
    S[i]=T[i];
  }
  sort(S, S+n);
  rep(i, n) if(T[i]!=S[i]) {
    jaki[V.size()]=i;
    T[V.size()]=T[i];
    V.pb({T[i], V.size()});
  }
  sort(all(V));
  n=V.size();
  if(n>s) {
    cout << -1 << '\n';
    return 0;
  }
  rep(i, n) F[i]=i;
  rep(i, n) {
    P[V[i].nd]=i;
    uni(i, V[i].nd);
  }
  rep(i, n) {
    if(mp.find(T[i])!=mp.end() && uni(mp[T[i]], i)) swap(P[i], P[mp[T[i]]]);
    mp[T[i]]=i;
  }
  rep(i, n) DO[P[i]]=i;
  vector<int>cykle;
  rep(i, n) if(fnd(i)==i) cykle.pb(i);
  s-=n;
  s=min(s, (int)cykle.size());
  if(s>2) {
    rep(i, s) P[DO[cykle[i]]]=cykle[(i+1)%s];
    vector<int>tmp;
    rep(i, s) tmp.pb(cykle[s-i-1]);
    ans.pb(tmp);
  }
  rep(i, n) if(!odw[i]) {
    vector<int>tmp;
    int p=i;
    while(!odw[p]) {
      odw[p]=1;
      tmp.pb(p);
      p=P[p];
    }
    ans.pb(tmp);
  }
  reverse(all(ans));
  cout << ans.size() << '\n';
  for(auto i : ans) {
    cout << i.size() << '\n';
    for(auto j : i) cout << jaki[j]+1 << " ";
    cout << '\n';
  }
}