#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n % 2 == 0)
        cout << (1LL << (n / 2));
    else
        cout << 0;


    return 0;
}