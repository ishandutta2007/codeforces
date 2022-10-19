#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll MATMAX = 110;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

struct Matrix
{
    ll n , m , mat[MATMAX][MATMAX];

    Matrix(ll N , ll M)
    {
        n = N;
        m = M;
        Fill(0);
    }

    void Fill(ll x)
    {
        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < m ; j++)
            {
                mat[i][j] = x;
            }
        }
    }

    Matrix getCopy()
    {
        Matrix ans = Matrix(n , m);
        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < m ; j++)
            {
                ans.mat[i][j] = mat[i][j];
            }
        }
        return ans;
    }

    Matrix operator+(Matrix x)
    {
        Matrix ans = Matrix(n , m);
        if(n != x.n || m != x.m)    return ans;

        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < m ; j++)
            {
                ans.mat[i][j] = (mat[i][j] + x.mat[i][j]) % MOD;
            }
        }
        return ans;
    }

    Matrix operator*(Matrix x)
    {
        Matrix ans = Matrix(n , x.m);
        if(m != x.n)    return ans;

        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < x.m ; j++)
            {
                for(ll k = 0 ; k < m ; k++)
                {
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * x.mat[k][j]) % MOD;
                }
            }
        }
        return ans;
    }

    Matrix operator^(ll x)
    {
        Matrix ans = Matrix(n , m);
        if(n != m)  return ans;

        for(ll i = 0 ; i < n ; i++) ans.mat[i][i] = 1;

        Matrix t = getCopy();

        while(x != 0)
        {
            if(x % 2 == 1)  ans = ans * t;
            x /= 2;
            t = t * t;
        }
        return ans;
    }
};

ll n , m;

int main()
{
    fast_io;

    cin >> n >> m;

    Matrix A = Matrix(1 , m);
    Matrix B = Matrix(m , m);

    A.Fill(1);
    B.mat[0][0] = B.mat[0][m - 1] = 1;
    for(ll i = 1 ; i < m ; i++) B.mat[i][i - 1] = 1;

    A = A * (B ^ (n - m + 1));
    cout << A.mat[0][0] << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/