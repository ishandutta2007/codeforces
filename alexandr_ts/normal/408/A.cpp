#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int k[N], qua[N];

int main() {
    string s;
    int n, t;
    cin >> n;
    fr(i, n)
        cin >> k[i];
    fr(i, n)
        fr(j, k[i]) {
            cin >> t;
            qua[i] += t;
        }
    fr(i, n)
        qua[i] = qua[i] * 5 + 15 * k[i];
    cout << *min_element(qua, qua + n);

}