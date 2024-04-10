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
    int n;
    cin >> n;
    map <int, int> m;
    fr(i, n) {
        int x;
        cin >> x;
        a[i] = x;
        m[x]++;
    }
    ll ans = 0;
    fr(i, n) {
        m[a[i]]--;
        frab(j, 1, 31)
            if (m.count((1 << j) - a[i]))
                ans += m[(1 << j) - a[i]];
        m[a[i]]++;
    }
    cout << ans / 2;
}