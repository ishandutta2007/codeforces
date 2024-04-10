#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >>n;
    n *= 2;
    vector<ll> a(n);
    for(ll &x :a)
        cin >> x;
    sort(a.begin(), a.end());
    if(a[0] == a.back())
        cout << -1;
    else
        for(ll x : a)
            cout << x << ' ';
    return 0;
}