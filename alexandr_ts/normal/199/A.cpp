#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

ll a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    a[0] = 1;
    a[1] = 1;
    ll n;
    cin >> n;
    cout << "0 0 " << n;
//    frab(i, 2, 1 + n) {
//        a[i] = a[i - 1] + a[i - 2];
//        if (a[i] == n) {
//            cout << a[i - 2] << " " << a[i - 2] << " " << a[i - 3] << endl;
//            return 0;
//        }
//    }
}