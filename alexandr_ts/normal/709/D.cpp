#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

ll cnt(ll x, bool ex) {
    if (!ex && x == 0)
        return 0;
    frab(i, 1, sqrt(2 * x) * 2 + 100)
        if (i * (i - 1) == 2 * x)
            return i;
    return -1;
}

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    ll a00, a01, a10, a11;
    bool ex = false;
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 + a01 + a10 + a11 == 0) {
        cout << "0";
        return 0;
    }
    if (a01 + a10)
        ex = true;
    ll a = cnt(a00, ex);
    ll b = cnt(a11, ex);
    //cout << a << "  " << b << endl;
    if (a == -1 || b == -1 || a * b != a10 + a01) {
        cout << "Impossible";
        return 0;
    }
    string ans;
    ll k = a01;
    ll sum = a + b;
    fr(i, sum) {
        //cout << i << endl;
        if (k >= b) {
            ans += "0";
            //cout << 0;
            k -= b;
        }
        else {
            ans += "1";
            //cout << 1;
            b--;
        }
    }
    cout << ans;
}