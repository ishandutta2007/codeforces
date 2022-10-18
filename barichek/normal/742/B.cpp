///written by Fekete///
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define next nastupniy
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


ll sqr(ll x){ return x * x; }

const double PI = acos(-1);
const int MAXN = 2e6 + 10;
const int INF = 1e9;
const ll md1 = 1e9 + 7;
const ll md2 = 1e9 + 9;
const int RNG = 1e7 + 10;

///end template///

ll cnt[1000000];
int n, x;

int main()
{
    ios::sync_with_stdio(0);
    
    scanf(II, &n, &x);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf(I, &k);
        cnt[k]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 100000; i++)
    {
        int j = x ^ i;
        if (j>100000||j<0) continue;
        if(i != j)
            ans += cnt[i] * cnt[j];
        else
            ans += (cnt[i] - 1) * cnt[i];
        
    }
    cout << ans / 2;
}