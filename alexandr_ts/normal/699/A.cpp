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

ll a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
	int n;
	ll ans = INF;
	cin >> n;
	string s;
	cin >> s;
	fr(i, n)
        cin >> a[i];
    fr(i, n - 1)
        if (s[i] == 'R' && s[i + 1] == 'L')
            ans = min(ans, (a[i + 1] - a[i]) / 2);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}