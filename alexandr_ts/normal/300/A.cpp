#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e3 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

ll a[N];
char s[N];

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    cout << 1 << " " << a[0] << endl;
    
    if (a[n - 1] > 0) {cout << 1 << " " << a[n - 1] << endl;
    
        cout << n - 2 << " ";
    frab(i, 1, n - 1)
        cout << a[i] << " ";cout << endl;
    }
    else {
        cout << 2 << " " << a[1] << " " << a[2] << endl;
        cout << n - 3 << " ";
    frab(i, 3, n)
        cout << a[i] << " ";cout << endl;
    }
}