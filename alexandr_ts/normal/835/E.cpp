#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 103;
const int N = 5010;

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    int pw = 0, cur = 1;
    while (cur * 2 <= n)
        cur *= 2, pw++;

    vector <int> dif;
    int bit = -1;

    fr(i, pw + 1) {
        vector <int> q;
        frab(j, 1, n + 1)
            if ((1 << i) & j)
                q.pb(j);
        int ans = 0;
        if (q.size()) {
            cout << "? " << q.size() << " ";
            for (auto t: q) cout << t << " ";
            cout << endl;
            cin >> ans;
        }
        int wait = 0;
        if (q.size() % 2) wait = x;
        if (wait != ans) {
            dif.pb(i);
            bit = i;
        }
    }

//    cout << bit << endl;
//    for (auto t: dif) cout << t << " ";cout << endl;

    int num1 = (1 << bit);
    fr(i, pw + 1)
        if (i != bit) {
            vector <int> q;
            frab(j, 1, n + 1)
                if ((j & (1 << bit)) && (j & (1 << i)))
                    q.pb(j);
            int ans = 0;
            if (q.size()) {
                cout << "? " << q.size() << " ";
                for (auto t: q) cout << t << " ";
                cout << endl;
                cin >> ans;
            }
            int wait = 0;
            if (q.size() % 2) wait = y;
            else wait = x ^ y;
            if (wait == ans)
                num1 |= (1 << i);
        }
    int num2 = num1;
    for (auto i: dif)
        num2 ^= (1 << i);
    cout << "! " << min(num1, num2) << " " << max(num1, num2) << endl;
}