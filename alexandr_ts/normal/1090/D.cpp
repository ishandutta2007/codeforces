#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);
    set<pair<int, int> > s;
    int x, y;
    fr(i, m) {
        scanf("%d %d", &x, &y);
        x--, y--;
        if (x > y)
            swap(x, y);
        s.insert({x, y});
    }

    int i1 = -1, j1 = -1;
    fr(i, n)
        if (i1 == -1)
            frab(j, i + 1, n) {
                if (i1 != -1)
                    break;
                if (!s.count({i, j})) {
                    i1 = i, j1 = j;
                    break;
                }
            }
        else
            break;
    if (i1 == -1) {
        cout << "NO";
        return 0;
    }

    vector<int> ans1(n), ans2(n);
    ans1[i1] = 1, ans1[j1] = 2;
    int last = 3;
    fr(i, n)
        if (!ans1[i])
            ans1[i] = last++;
    ans2 = ans1;
    ans2[j1] = 1;
    cout << "YES\n";
    fr(i, n)
        cout << ans1[i] << " ";cout << endl;
    fr(i, n)
        cout << ans2[i] << " ";
}