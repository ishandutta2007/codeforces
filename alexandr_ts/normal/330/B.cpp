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

bool used[N];

int main() {
    int n, m, v, u;
    cin >> n >> m;
    fr(i, m) {
        cin >> v >> u;
        used[v - 1] = used[u - 1] = true;
    }
    fr(i, n)
        if (!used[i]) {
            cout << n - 1 << endl;
            fr(j, n)
                if (i != j)
                    cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
}