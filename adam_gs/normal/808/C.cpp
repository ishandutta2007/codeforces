#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107;
int T[LIM], ile[LIM];
int main() {
  ios_base::sync_with_stdio(0);
  int n, w;
  cin >> n >> w;
  rep(i, n) {
    cin >> T[i];
    ile[i]=(T[i]+1)/2;
    w-=ile[i];
  }
  if(w<0) {
    cout << -1 << '\n';
    return 0;
  }
  while(w--) {
    int ma=0, ind=-1;
    rep(i, n) if(ile[i]<T[i] && T[i]>ma) {
      ind=i;
      ma=T[i];
    }
    ++ile[ind];
  }
  rep(i, n) cout << ile[i] << " ";
  cout << '\n';
}