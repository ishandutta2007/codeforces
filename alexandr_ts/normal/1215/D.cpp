#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 10;
const ld EPS = 1e-8;
const ld PI = acos(-1);
const int M = 20;
const int N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int qm1 = count(begin(s), begin(s) + n / 2, '?');
    int qm2 = count(begin(s) + n / 2, end(s), '?');
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            if (i < n / 2)
                sum1 += (s[i] - '0');
            else
                sum2 += (s[i] - '0');
        }
    }

    sum1 = 2 * sum1 + qm1 * 9;
    sum2 = 2 * sum2 + qm2 * 9;

    if (sum1 != sum2) {
        cout << "Monocarp\n";
    } else {
        cout << "Bicarp\n";
    }

}

int main() {
    //freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}