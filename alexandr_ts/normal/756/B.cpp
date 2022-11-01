#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int M = 1e7 + 1;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int last = 0;

    fr(i, n) {
        cin >> a[i];
        int newans;
        if (i)
            newans = b[i - 1] + 20;
        else
            newans = 20;

        if (i && a[i - 1] + 89 >= a[i]) {
            int l = -1, r = i - 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (a[m] + 89 >= a[i])
                    r = m;
                else
                    l = m;
            }
            //cout << i << " 89 " << r << endl;
            newans = min(newans, (r ? b[r - 1] : 0) + 50);
        }


        if (i && a[i - 1] + 1439 >= a[i]) {
            int l = -1, r = i - 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (a[m] + 1439 >= a[i])
                    r = m;
                else
                    l = m;
            }
            newans = min(newans, (r ? b[r - 1] : 0) + 120);
        }
        b[i] = newans;
    }
    fr(i, n)
        if (!i)
            cout << b[i] << endl;
        else
            cout << b[i] - b[i - 1] << endl;


}