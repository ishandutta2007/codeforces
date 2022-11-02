#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
pii a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    set< pair< pii, int > > S;
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int A = a[i].second - a[j].second;
            int B = a[j].first - a[i].first;
            if(A < 0) {
                A *= -1;
                B *= -1;
            }
            int C = -A * a[i].first - B * a[i].second;
            int g = __gcd(abs(A), __gcd(abs(B), abs(C)));
            A/=g;
            B/=g;
            C/=g;
            S.insert(make_pair(make_pair(A, B), C));
        }
    }
    map< pii, int > M;
    ll ans = (S.size()-1ll) * (S.size())/2;
    for(auto x: S) {
        ans -= M[x.first];
        M[x.first]++;
    }
    cout << ans << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}