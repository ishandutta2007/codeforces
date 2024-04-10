#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int p1 = find(a, a + n, 1) - a + 1;
    int p2 = find(a, a + n, n) - a + 1;
    //cout << p1 << " " << p2;
    int ans = abs(p1 - p2);
    ans = max(ans, abs(p1 - 1));
    ans = max(ans, abs(n - p1));
    ans = max(ans, abs(p2 - 1));
    ans = max(ans, abs(n - p2));
    cout << ans;

}