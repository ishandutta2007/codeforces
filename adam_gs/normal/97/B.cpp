#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
vector<pair<int,int>>solve(vector<pair<int,int>>V) {
  if(V.size()<2) return V;
  vector<pair<int,int>>ans, A, B;
  int x=(V.size()-1)/2;
  for(auto i : V) ans.pb({V[x].st, i.nd});
  rep(i, x+1) A.pb(V[i]);
  for(int i=x+1; i<V.size(); ++i) B.pb(V[i]);
  A=solve(A);
  B=solve(B);
  for(auto i : A) ans.pb(i);
  for(auto i : B) ans.pb(i);
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<pair<int,int>>V;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    V.pb({a, b});
  }
  sort(all(V));
  vector<pair<int,int>>ans=solve(V), T;
  sort(all(ans));
  T.pb(ans[0]);
  for(auto i : ans) if(T.back()!=i) T.pb(i);
  cout << T.size() << '\n';
  for(auto i : T) cout << i.st << " " << i.nd << '\n';
}