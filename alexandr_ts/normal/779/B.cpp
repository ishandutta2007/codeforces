#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N], b[N], c[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    int k;
    cin >> s >> k;
    int cnt = 0;
    int i = s.size();
    i--;
    for (;i >= 0 && cnt < k; i--)
        if (s[i] == '0') cnt++;
    if (cnt < k) {
        cout << (int)s.size() - 1 << endl;
    }
    else {
        cout << (int)s.size() - i - k - 1;
    }
}