#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

bool used[N], used2[N];
    int qua = 0;
    int ans = 0;
    int n;


void ch() {
    if (qua == n)
    {
        cout << ans;
        exit(0);
    }
}

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        if (i % 2 == 0)
            fr(j, n) {
                if (!used[j] && a[j] <= qua)
                    used[j] = true, qua++;
                ch();
            }
        else
            for (int j = n - 1; j >= 0; j--) {
                if (!used[j] && a[j] <= qua)
                    used[j] = true, qua++;
                ch();
            }
        ans++;
    }
}