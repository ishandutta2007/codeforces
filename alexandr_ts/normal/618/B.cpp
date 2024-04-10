#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 2e3;
const int INF = 2e9;

int a[N][N];
int mx[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n)
        fr(j, n)
            cin >> a[i][j];
    fr(i, n)
        mx[i] = *max_element(a[i], a[i] + n);
    fr(i, n)
        if (mx[i] == n - 1) {
            mx[i] = n;
            break;
        }
    fr(i, n)
        cout << mx[i] << " ";
}