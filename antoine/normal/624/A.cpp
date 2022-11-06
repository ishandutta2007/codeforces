#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll d,L,v1,v2;
    cin >> d >> L >> v1 >> v2;

    L -= d;
    ll v = v1 + v2;

    cout << fixed << setprecision(11) << double(L)/v;

    return 0;
}