#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];
bool used[N];

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    //reverse(a, a + n);
    //fr(i, n)
      //  cout << a[i] << " ";cout << endl;
    int curx = n / 2;
    fr(i, n)
        if (!used[i]) {
            while (curx < n && a[curx] < 2 * a[i])
                curx++;
            used[curx] = true;
            curx++;
        }
    //fr(i, n)
       // cout << used[i] << " ";cout << endl;
    cout << n - accumulate(used, used + n, 0);

}