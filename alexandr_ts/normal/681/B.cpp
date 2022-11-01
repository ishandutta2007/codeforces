#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    frab(i, 0, 1001)
        frab(j, 0, 10001) {
            ll t = n - 1234567ll * (ll)i - 123456ll * (ll)j;
            if (t >= 0 && t % 1234 == 0) {
                //cout << i << " " << j << " " << t / 1234 << endl;
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}