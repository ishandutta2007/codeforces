#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 1;
const int M = 19;
const ld EPS = 1e-10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int a[(1 << M)];

int main() {
    //freopen ("manyangle.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n) {
        char t;
        cin >> t;
        string s;
        cin >> s;
        if (t == '+') {
            while (s.size() < 19)
                s = '0' + s;
            int mask = 0;
            fr(i1, M)
                if ((s[i1] - '0') % 2)
                    mask += (1 << i1);
            a[mask]++;
        }
        if (t == '-') {
            while (s.size() < 19)
                s = '0' + s;
            int mask = 0;
            fr(i1, M)
                if ((s[i1] - '0') % 2)
                    mask += (1 << i1);
            a[mask]--;
        }
        if (t == '?') {
            while (s.size() < 19)
                s = '0' + s;
            int mask = 0;
            fr(i1, M)
                if ((s[i1] - '0') % 2)
                    mask += (1 << i1);
            cout << a[mask] << endl;
        }
    }
}