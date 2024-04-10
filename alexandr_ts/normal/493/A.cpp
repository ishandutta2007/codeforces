#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 1e6;
const ll M = 311;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

int q1[N], q2[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    fr(i, n) {
        int mn, num;
        char card, team;
        cin >> mn >> team >> num >> card;
        if (team == 'h') {
            q1[num]++;
            if (card == 'r')
                q1[num]++;
            if (q1[num] >= 2) {
                cout << s << " " << num << " " << mn << endl;
                q1[num] = -INF;
            }
        }
        else {
            q2[num]++;
            if (card == 'r')
                q2[num]++;
            if (q2[num] >= 2) {
                cout << t << " " << num << " " << mn << endl;
                q2[num] = -INF;
            }
        }
    }
}