#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    int n, a1;
    cin >> n >> a1;
    fr(i, n)
        cin >> a[i];
    a1--;
    int ans = 0;
    int l = a1, r = a1;
    while (l >= 0 && r < n) {
        if (l == r && a[l]) {
            ans++;
        }
        else if (a[l] && a[r])
            ans += 2;
        l--, r++;
    }
    while (l >= 0 || r < n) {
        if (l >= 0 && a[l] || r < n && a[r])
            ans++;
        l--, r++;
    }
    cout << ans;
}