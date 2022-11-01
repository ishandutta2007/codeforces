#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    ll n; cin >> n; n++;
    if(n == 1) cout << 0;
    else if(n & 1) cout << n;
    else cout << n / 2;
}