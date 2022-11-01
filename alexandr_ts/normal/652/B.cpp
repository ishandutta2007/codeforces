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
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    vector <int> b, c;
    fr(i, (n + 1) / 2)
        b.pb(a[i]);
    frab(i, (n + 1) / 2, n)
        c.pb(a[i]);
    //reverse(c.begin(), c.end());
    fr(i, n / 2)
        cout << b[i] << " " << c[i] << " ";
    if (n % 2)
        cout << b.back();
}