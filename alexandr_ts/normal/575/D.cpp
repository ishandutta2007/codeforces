#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 1e6 + 1;



int main() {
    //freopen("a.in", "r", stdin);
    int n = 1000;
    cout << n * 2 + 1 << endl;
    fr(i, n) {
        cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << endl;
        //cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << endl;
    }
    cout << 1 << " " << 1 << " " << 2 << " " << 2 << endl;
    fr(i, n) {
        cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << endl;
        //cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << endl;
    }
}