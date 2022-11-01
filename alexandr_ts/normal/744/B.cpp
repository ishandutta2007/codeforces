#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 1e3 + 10;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e9 - 6;

int ans[N];

int main() {
    //freopen("a.in", "r", stdin);
	int n;
	cin >> n;
    fill(ans, ans + n, INF);
//    int pw = 0;
//    int n1 = n;
//    while (n1)
//        n1 /= 2, pw++;
//    pw--;

    for (int po = 0; (1 << po) < n; po++) {
        int cnt = 0;

        vector <int> tmp, tmp2;
        fr(i, n)
            if (i & (1 << po))
                tmp.push_back(i);
            else
                tmp2.push_back(i);

        cout << tmp.size() << "\n";
        fr(i, tmp.size())
            cout << tmp[i] + 1 << " ";
        cout << endl;

        int x;
        fr(i, n) {
            cin >> x;
            if (!(i & (1 << po)))
                ans[i] = min(ans[i], x);
        }

        cout << tmp2.size() << "\n";
        fr(i, tmp2.size())
            cout << tmp2[i] + 1 << " ";
        cout << endl;

        fr(i, n) {
            cin >> x;
            if (i & (1 << po))
                ans[i] = min(ans[i], x);
        }

    }
    cout << -1 << "\n";
    fr(i, n)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}