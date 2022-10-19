#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
ll T[LIM];
map<ll,int>mp, mp2;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll akt=0, sum=0;
  rep(i, n) {
    cin >> T[i];
    sum+=T[i];
    ++mp2[T[i]];
  }
  if(sum%2==0 && mp2[sum/2]) {
    cout << "YES\n";
    return 0;
  }
  rep(i, n) {
    akt+=T[i];
    sum-=T[i];
    --mp2[T[i]];
    ++mp[T[i]];
    if(akt==sum) {
      cout << "YES\n";
      return 0;
    }
    if(abs(sum-akt)%2==1) continue;
    if(akt>sum) {
      if(mp[(akt-sum)/2]) {
        cout << "YES\n";
        return 0;
      }
    } else {
      if(mp2[(sum-akt)/2]) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}