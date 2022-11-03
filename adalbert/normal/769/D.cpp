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
const ll INF = 1e18 + 1;
const int RNG = 1e8 + 10;
const pii turns[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

///end template///

int n, k;
int cntOfBits[MAXN];
int cntOfNumbers[MAXN];
ll ans;

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    scanf(II, &n, &k);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf(I, &x);
        cntOfNumbers[x]++;
    }

    for(int i = 0; i < MAXN; i++)
        cntOfBits[i] = __builtin_popcountll(i);
    for(int i = 0; i <= 1e4; i++)
    {
        if(k == 0)
            ans += ll(cntOfNumbers[i]) * ll(cntOfNumbers[i] - 1) / 2;
        for(int j = i + 1; j <= 1e4; j++)
            if(cntOfBits[i ^ j] == k)
                ans += ll(cntOfNumbers[i]) * ll(cntOfNumbers[j]);
    }

    cout << ans;
}