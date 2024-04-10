#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n - 1)
        fr(j, n - 1) {
            int a1 = min(a[i], a[i + 1]), a2 = max(a[i], a[i + 1]);
            int b1 = min(a[j], a[j + 1]), b2 = max(a[j], a[j + 1]);
            if (a1 < b1 && b1 < a2 && b2 > a2) {
                cout << "yes";
                return 0;
            }
        }
    cout << "no";
}