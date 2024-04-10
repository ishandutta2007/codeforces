#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int minl[N], maxl[N], ans[N];

int main() {
    int n, t;
    cin >> n;
    set <int> s;
    fr(i, n) {
        cin >> t;
        if (t >= 1 && t <= n) s.insert(t);
    }
    cout << n - (int)s.size();
}