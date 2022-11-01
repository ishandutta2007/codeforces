#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 10;
const ll INF = 2e9;
const ll ALPH = 300;
const int MOD = 1e9 + 7;
int st[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n;
    char t;
    cin >> n;
    fr(i, 4) fr(j, 4) {cin >> t; if (t != '.') st[t]++;}
    int x = *max_element(st, st + 1000);
    if (x > 2 * n)
        cout << "NO";
    else
        cout << "YES";
}