/** I can do this all day **/

#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"

//void add(int I, int value){seg[I += MAXN] = value;for (I >>= 1; I; I >>= 1){seg[I] = __gcd(seg[I << 1], seg[I << 1 | 1]);}}

//int query(int l, int r){int ans = seg[l + MAXN];for (l += MAXN, r += MAXN + 1; l < r; l >>= 1, r >>= 1){if(l & 1) ans = __gcd(ans, seg[l ++]);if(r & 1) ans = __gcd(ans, seg[-- r]);}return ans;}

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 8e18;
const int LOG = 20;

ll pw(ll a , ll b, ll mod)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % mod, b / 2, mod)) % mod : pw(a * a % mod, b / 2, mod))); }

int X[MAXN], H[MAXN], v[MAXN], mark[MAXN], n, m;

vector < int > _, moves;

bool comp(int i, int j) { return X[i] < X[j]; }

bool CanR(int id, int place)
{
        int init = H[id], x = X[id];
        for(int i = x; i <= place; i++)
        {
                init += v[i];
                if(init < 0)return 0;
        }
        return 1;
}

bool CanL(int id, int place)
{
        int init = H[id], x = X[id];
        for(int i = x; i >= place; i--)
        {
                init += v[i];
                if(init < 0)return 0;
        }
        return 1;
}

bool check(int x)
{
        moves.clear();
        for(int i = 1; i <= m; i++) { mark[i] = 0; }
        vector < int > L, R;
        for(auto cu : _)
        {
                if(X[cu] <= x) { L.push_back(cu); }
                else { R.push_back(cu); }
        }
        //first L
        //cout << "L" << endl;
        reverse(all(L));
        int last = x, f1 = 1, f2 = 1;
        for(auto cu : L)
        {
                f1 = CanR(cu, last);
                if(f1)
                {
                        moves.push_back(cu);
                        mark[cu] = 1;
                        last = X[cu] - 1;
                }
        }
        if(!L.empty())last = x + 1;
        else
        {
                last = x;
        }
        for(auto cu : R)
        {
                f2 = CanL(cu, last);
                if(f2)
                {
                        moves.push_back(cu);
                        mark[cu] = 1;
                        last = X[cu] + 1;
                }
        }
        if(f1 && f2)
        {
                for(int i = 1; i <= m; i++)
                {
                        if(mark[i] == 0)
                        {
                                moves.push_back(i);
                        }
                }
                return 1;
        }
        //first R
        //cout << "R" << endl;
        moves.clear();
        for(int i = 1; i <= m; i++) { mark[i] = 0; }
        if(!R.empty())last = x + 1;
        else{ last = x; }
        f1 = 1, f2 = 1;
        for(auto cu : L)
        {
                f1 = CanR(cu, last);
                if(f1)
                {
                        moves.push_back(cu);
                        mark[cu] = 1;
                        last = X[cu] - 1;
                }
        }
        last = x;
        for(auto cu : R)
        {
                f2 = CanL(cu, last);
                if(f2)
                {
                        moves.push_back(cu);
                        mark[cu] = 1;
                        last = X[cu] + 1;
                }
        }
        if(f1 && f2)
        {
                for(int i = 1; i <= m; i++)
                {
                        if(mark[i] == 0)
                        {
                                moves.push_back(i);
                        }
                }
                return 1;
        }
        return 0;
}

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    cin >> n >> m;
    for(int i = 1; i <= m ;i++)
    {
            cin >> X[i] >> H[i];
            _.push_back(i);
    }
    for(int i = 1; i <= n; i++) { cin >> v[i]; }
    sort(all(_), comp);
    for(int i = 1; i <= n; i++)
    {
            if(check(i))
            {
                    cout << i << endl;
                    for(auto x : moves)
                    {
                            cout << x << " ";
                    }
                    return 0;
            }
    }
    cout << -1, 0;
    return 0;
}