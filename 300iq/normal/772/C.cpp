/*

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = max(x, y);
}

const int maxn = 2e5 + 100, inf = 1e9 + 100, sq = 300;

int n, m, mod;

ll bpow(ll x, ll y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll ret = bpow(x, y >> 1);
    ret = (ret * ret) % mod;
    if (y & 1)
        ret = (ret * x) % mod;
    return ret;
}

int FI;

int bdiv(ll x, ll y){
    return (x * bpow(y, FI - 1)) % mod;
}

vector<int> del, del1;

int mas[maxn];

int gcd(int x, int y){
    if (x == 0 || y == 0)
        return mod;
    return __gcd(x, y);
}

vector<int> q[maxn];

int dp[maxn], par[maxn];

vector<int> g;

int cn;

int fun(int x){
    if (x == mod)
        return 0;
    return x;
}
int phi () {
 int result = cn;
 for (int i=2; i*i<=cn; ++i)
  if (cn % i == 0) {
   while (cn % i == 0)
    cn /= i;
   result -= result / i;
  }
 if (cn > 1)
  result -= result / cn;
 return result;
}
int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    scanf("%d %d", &n, &m);
    mod = m;
    cn = mod;
    FI = phi();
    for (int i = 0; i < m; i++)
        mas[i] = 1, par[i] = -1;
    par[m] = -1;
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        mas[x] = 0;
    }
    if (m == 1){
        if (n == 0)
            printf("1\n0");
        else
            printf("0\n");
        return 0;
    }
    for (int i = 1; i <= sqrt(m); i++)
    if (m % i == 0){
        del.push_back(i);
        if (i * i != m)
            del1.push_back(m / i);
    }
    reverse(del1.begin(), del1.end());
    for (int i = 0; i < del1.size(); i++)
        del.push_back(del1[i]);
    for (int i = 0; i < m; i++)
    if (mas[i])
        q[gcd(i, m)].push_back(i);
    n = del.size();
    for (int i = 0; i < n; i++){
        int id = del[i];
        dp[id] += q[id].size();
        for (int j = i + 1; j < n; j++){
            int to = del[j];
            if (to % id == 0 && dp[to] < dp[id])
                dp[to] = dp[id], par[to] = id;
        }
    }
    printf("%d\n", dp[m]);
    int now = m;
    while (now >= 0){
        g.push_back(now);
        now = par[now];
    }
    reverse(g.begin(), g.end());
    int last = 1;
    for (int i = 0; i < g.size(); i++){
        int id = g[i];
        for (int j = 0; j < q[id].size(); j++){
            ll x = gcd(last, m), y = gcd(q[id][j], m);
            ll val = y / x;
            x = last / x, y = q[id][j] / y;
            val = (val * bdiv(y, x)) % mod;
            printf("%d ", (int)val), last = q[id][j];
        }
    }
}