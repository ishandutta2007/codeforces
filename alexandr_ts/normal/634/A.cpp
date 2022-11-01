#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, ll> pr;

const int N = 2e5 + 2;
const int INF = 2e9 + 10;
const int ALPH = 300;
const ll MOD = 1e9 + 7;
const ll P = 29;

int a[N], b[N];

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    int ad1 = 0, ad2 = 0;
    cin >> n;
    fr(i, n) {
        cin >> a[i - ad1];
        if (a[i - ad1] == 0)
            ad1 = 1;
    }
    fr(i, n) {
        cin >> b[i - ad2];
        if (b[i - ad2] == 0)
            ad2 = 1;
    }
    int pos = 0;
    fr(i, n - 1)
        if (b[i] == a[0]) {

            pos = i;
            break;
        }
    rotate(b, b + pos, b + n - 1);
    fr(i, n - 1)
        if (a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

}