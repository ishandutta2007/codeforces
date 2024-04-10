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

int a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    int n, pos;
    cin >> n >> pos;
    fr(i, n)
        cin >> a[i];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(a, a + n);
    int ans1 = 0, ans2 = 0;
    ans1 = min(abs(pos - a[1]) + a[n - 1] - a[1], abs(pos - a[n - 1]) + a[n - 1] - a[1]);
    ans2 = min(abs(pos - a[0]), abs(pos - a[n - 2])) + a[n - 2] - a[0];
    cout << min(ans1, ans2);
}