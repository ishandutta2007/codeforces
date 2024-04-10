#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 1e3 + 10;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        int x = a[i];
        frab(j, 1, sqrt(x) + 2)
            if (x % j == 0 && j <= x / j)
                if (j == x / j)
                    b[j]++;
                else
                    b[j]++, b[x / j]++;
    }
    cout << max(1, *max_element(b + 2, b + N));

}