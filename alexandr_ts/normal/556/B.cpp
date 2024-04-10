#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        bool er = false;
        fr(j, n) {
            if (j % 2) {
                if ((a[j] + i) % n != j) {
                    er = true;
                    break;
                }
            }
            else {
                if ((a[j] - i + n) % n != j) {
                    er = true;
                    break;
                }
            }
        }
        if (!er) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

 }