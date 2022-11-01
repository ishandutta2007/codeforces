#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int p1[N], p2[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    frab(i, 1, n + 1)
        p1[i] = p1[i - 1] + s[i - 1] - '0';

    ll ans = 0;
    fr(i, m) {
        int r = min(n - 1, i);
        int d = m - n;
        int l = max(0, i - d);
        //cout << l << " " << r << " " << i << endl;
        if (r < l)
            continue;
        if (t[i] == '1')
            ans += (r - l + 1) - (p1[r + 1] - p1[l]);
        else
            ans += p1[r + 1] - p1[l];
    }
    cout << ans;
}