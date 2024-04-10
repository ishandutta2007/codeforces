#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, m;
pii a[3];
ll dis(pii a, pii b) {
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return x * x + y * y;
}
void solve() {
    for(int i = 0; i < 3; i++) cin >> a[i].first >> a[i].second;

    if(dis(a[0], a[1]) != dis(a[1], a[2])) {
        cout << "No\n";
        return;
    }
    ll x1 = a[1].first-a[0].first;
    ll y1 = a[1].second-a[0].second;
    ll x2 = a[2].first-a[0].first;
    ll y2 = a[2].second-a[0].second;
    if(x1 < 0) {
        x1 *= -1;
        y1 *= -1;
    }else if(y1 < 0) {
        y1 *= -1;
    }
    if(x2 < 0) {
        x2 *= -1;
        y2 *= -1;
    }else if(y2 < 0) {
        y2 *= -1;
    }
    ll g = __gcd(abs(x1), abs(y1));
    x1/=g;
    y1/=g;
    g = __gcd(abs(x2), abs(y2));
    x2/=g;
    y2/=g;
    if(make_pair(x1, y1) == make_pair(x2, y2)) {
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
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