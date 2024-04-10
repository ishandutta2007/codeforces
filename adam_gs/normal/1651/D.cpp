#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=1e9+7;
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
pair<int,int>T[LIM], zle={-1, -1};
map<pair<int,int>,pair<int,int>>ans;
void solve() {
  int n;
  cin >> n;
  rep(i, n) {
    cin >> T[i].st >> T[i].nd;
    ans[{T[i].st, T[i].nd}]=zle;
  }
  queue<pair<int,int>>q;
  rep(i, n) rep(j, 4) if(ans[{T[i].st+dx[j], T[i].nd+dy[j]}]!=zle) {
    q.push({T[i].st+dx[j], T[i].nd+dy[j]});
    ans[{T[i].st+dx[j], T[i].nd+dy[j]}]={T[i].st+dx[j], T[i].nd+dy[j]};
  }
  while(!q.empty()) {
    int a=q.front().st, b=q.front().nd; q.pop();
    rep(i, 4) if(ans[{a+dx[i], b+dy[i]}]==zle) {
      ans[{a+dx[i], b+dy[i]}]=ans[{a, b}];
      q.push({a+dx[i], b+dy[i]});
    }
  }
  rep(i, n) cout << ans[{T[i].st, T[i].nd}].st << " " << ans[{T[i].st, T[i].nd}].nd << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}