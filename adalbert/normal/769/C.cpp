///Lol kek cheburek///
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase

#define elif else if
#define all(v) (v).begin(),(v).end()
#define len(s) int((s).size())

#define fi first
#define se second
#define x first
#define y second

#define fpos krevedka
#define left Levo
#define right ishtenem
#define next nastupniy
#define prev poperedniy
#define div dilyty_sukotay

#define I64 "%lld"

#define I "%d"
#define II I I
#define III II I
#define IIII II II
#define IIIII III II
#define IIIIII III III
#define IIIIIII IIII III
#define IIIIIIII IIII IIII

#define dbg cout << "dbg\n"
#define files(name) freopen(name".in", "r", stdin);freopen(name".out","w", stdout);
#define AUPCfiles(name) freopen(name".dat", "r", stdin);freopen(name".sol","w", stdout);


ll sqr(ll x) {return x * x;}

const ll md = 1e9 + 7;
const ll md2 = 2e9 + 7;
const ld PI = acos(-1);
const int MAXN = 2e5 + 10;
const int INF = 1e9 + 1;
const int RNG = 1e8 + 10;
const pii turns[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
const char signs[4] = {'D', 'L', 'R', 'U'};
///end template///

int n, m, x, y, k;
bool a[2000][2000];
queue<pii> q;
int d[2000][2000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            d[i][j] = INF;
            char c;
            cin >> c;
            a[i][j] = (c != '*');
            if(c == 'X')
            {
                x = i;
                y = j;
            }
        }
    d[x][y] = 0;
    q.push(mp(x, y));
    while(!q.empty())
    {
        pii v = q.front();
        q.pop();
        for(auto turn : turns)
        {
            pii to = mp(v.x + turn.x, v.y + turn.y);
            if(to.x < 1 || to.x > n || to.y < 1 || to.y > m) continue;
            if(a[to.x][to.y] && d[to.x][to.y] > d[v.x][v.y] + 1)
                {
                    q.push(to);
                    d[to.x][to.y] = d[v.x][v.y] + 1;
                }
        }
    }

    string ans = "";
    for(int i = 0; i < k; i++)
    {
        bool found = false;
        for(int j = 0; j < 4; j++)
        {
            pii turn = turns[j];
            pii to = mp(x + turn.x, y + turn.y);
            if(to.x < 1 || to.x > n || to.y < 1 || to.y > m) continue;
            if(d[to.x][to.y] <= k - i - 1)
            {
                found = true;
                ans += signs[j];
                x = to.x; y = to.y;
                break;
            }
        }
        if(!found) return cout << "IMPOSSIBLE", 0;
    }

    cout << ans;




}