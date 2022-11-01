#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-9;

int main() {
    //freopen("a.in", "r", stdin);
    int n, t;
    vector <int> a1, a2, a3;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1)
            a1.pb(i + 1);
        if (t == 2)
            a2.pb(i + 1);
        if (t == 3)
            a3.pb(i + 1);
    }
    int qua = min(min((int)a1.size(), (int)a2.size()), (int)a3.size());
    cout << qua << endl;
    for (int i = 0; i < qua; i++)
        cout << a1[i] << " " << a2[i] << " " << a3[i] << endl;
}