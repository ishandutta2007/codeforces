#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 1000 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;

int x1[N], y1[N], x2[N], y2[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] += M, y1[i] += M;
        x1[i] %= 2;
        y1[i] %= 2;
    }
    cout << "YES" << endl;
    fr(i, n)
        if (x1[i] && y1[i])
            cout << 1 << endl;
        else if (x1[i] && !y1[i])
            cout << 2 << endl;
        else if (!x1[i] && y1[i])
            cout << 3 << endl;
        else
            cout << 4 << endl;
}