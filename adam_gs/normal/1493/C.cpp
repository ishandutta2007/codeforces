#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n, k;
  string s;
  cin >> n  >> k >> s;
  if(n%k) {
    cout << -1 << '\n';
    return;
  }
  int ile[26], pref=0;
  rep(i, 26) ile[i]=0;
  rep(i, n) {
    ile[s[i]-'a']=(ile[s[i]-'a']+1)%k;
    int sum=0;
    rep(j, 26) sum+=(k-ile[j])%k;
    if(sum>n-i-1) continue;
    if(i==n-1) {
      cout << s << '\n';
      return;
    }
    if(s[i+1]=='z') continue;
    if(sum<n-i-1) pref=i+1;
    for(int j=s[i+1]-'a'+1; j<26; ++j) if(ile[j]) pref=i+1;
  }
  rep(i, 26) ile[i]=0;
  rep(i, pref) {
    cout << s[i];
    ile[s[i]-'a']=(ile[s[i]-'a']+1)%k;
  }
  int sum=n-pref;
  rep(i, 26) {
    ile[i]=(k-ile[i])%k;
    sum-=ile[i];
  }
  if(!ile[s[pref]-'a'+1] && sum) {
    ile[s[pref]-'a'+1]+=k; sum-=k;
  }
  while(sum) {
    ile[0]+=k; sum-=k;
  }
  for(int i=s[pref]-'a'+1; i<26; ++i) if(ile[i]) {
    cout << char('a'+i);
    --ile[i];
    break;
  }
  rep(i, 26) while(ile[i]--) cout << char('a'+i);
  cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}