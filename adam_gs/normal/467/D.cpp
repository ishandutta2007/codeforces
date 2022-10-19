#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
vector<int>V[LIM];
int T[LIM], iler[LIM], iled[LIM], odw[LIM], k;
pair<int,int>kraw[LIM];
map<string,int>mp;
void dodaj(string s) {
  if(mp[s]) return;
  ++k;
  mp[s]=k;
  iled[k]=s.size();
  for(auto i : s) if(i=='r') ++iler[k];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> m;
  rep(i, m) {
    string s;
    cin >> s;
    rep(j, s.size()) s[j]=tolower(s[j]);
    dodaj(s);
    T[i]=mp[s];
  }
  int n;
  cin >> n;
  rep(i, n) {
    string a, b;
    cin >> a >> b;
    rep(j, a.size()) a[j]=tolower(a[j]);
    rep(j, b.size()) b[j]=tolower(b[j]);
    dodaj(a);
    dodaj(b);
    V[mp[b]].pb(mp[a]);
  }
  priority_queue<pair<pair<int,int>,int>>q;
  rep(i, k) q.push({{-iler[i+1], -iled[i+1]}, i+1});
  while(!q.empty()) {
    int r=-q.top().st.st, d=-q.top().st.nd, p=q.top().nd; q.pop();
    if(odw[p]) continue;
    odw[p]=1;
    iler[p]=r; iled[p]=d;
    for(auto i : V[p]) if(!odw[i]) q.push({{-iler[p], -iled[p]}, i});
  }
  ll ansr=0, ansd=0;
  rep(i, m) {
    ansr+=iler[T[i]];
    ansd+=iled[T[i]];
  }
  cout << ansr << " " << ansd << '\n';
}