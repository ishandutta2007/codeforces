#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
vector<int>V[26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  rep(i, n) V[s[i]-'a'].pb(i);
  int m;
  cin >> m;
  while(m--) {
    string s;
    cin >> s;
    int ile[26];
    rep(i, 26) ile[i]=0;
    for(auto i : s) ++ile[i-'a'];
    int ans=0;
    rep(i, 26) if(ile[i]) ans=max(ans, V[i][ile[i]-1]+1);
    cout << ans << '\n';
  }
}