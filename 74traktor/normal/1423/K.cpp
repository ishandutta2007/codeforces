#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*#ifdef karpovich
        freopen("input.txt", "r", stdin);
    #endif*/

    /*int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        bool ok = 0;
        cout << i << ": ";
        for (int j = 1; j <= n; j ++) {
            if (i != j) {
                int g = __gcd(i, j);
                if (g + i / g > j / g && g + j / g > i / g && g < i / g + j / g) {
                    cout << j << ' ' ;
                }
            }
        }

        cout << endl;
    }*/

    int m;
    cin >> m;

    vector<pii> a(m);

    for (int i = 0; i <m ; i++) {
        cin >> a[i].x;
        a[i].y = i;
    }

    sort(a.begin(), a.end());
    vector<int> answ(m);
    int j = 0;

    bitset<1000009> nprime;
    nprime[0] = 1;
    nprime[1] = 1;

    int cntprimes = 1;

    while (j < m && a[j].x == 1) {
        answ[a[j].y] = 1;
        j++;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (nprime[i] == 0) {
            for (int t = i * i; t <= 1000000; t += i) {
                nprime[t] = 1;
            }

            cntprimes++;
        }

        else {
            int ret = round(sqrt(i));
            if (ret * ret == i && nprime[ret] == 0) cntprimes--;
        }

        //cout << j << ' '<< cntprimes << ' '<<i<< endl;
        while (j < m && a[j].x == i) {
            answ[a[j].y] = cntprimes;
            j++;
        }
    }

    for (auto u : answ) {
        cout << u << "\n";
    }

    return 0;
}