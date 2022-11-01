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
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector <bool> v;
    while (true) {
        if (a1 >= h2) {
            v.pb(1);
            break;
        }
        if (a2 >= h1) {
            v.pb(0);
            h1 += c1;
            h1 -= a2;
        }
        else {
            v.pb(1);
            h2 -= a1;
            h1 -= a2;
        }
    }

    cout << v.size() << endl;
    for (auto i: v)
        if (i)
            printf("STRIKE\n");
        else
            printf("HEAL\n");
}