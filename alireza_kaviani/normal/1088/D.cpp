#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 40;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll a , b , t , bitA[MAXN] , bitB[MAXN] , compare[MAXN][10];

ll query(ll x , ll y)
{
    ll res;
    cout << "? " << x << sep << y << endl;
    cin >> res;
    return res;
}

void equalQuery(ll i , ll j)
{
    compare[i][j] = query(a + t , b);
    if(compare[i][j] == 1)
    {
        bitA[i] = bitB[i] = 0;
    }
    else
    {
        bitA[i] = bitB[i] = 1;
        a += t;
        b += t;
    }
}

void greaterQuery(ll i , ll j)
{
    compare[i][j] = query(a + t - 1 , b + t - 1);
    if(compare[i][j] == 1)
    {
        bitA[i] = 1;
        bitB[i] = 0;
        a += t;
    }
    else
    {
        equalQuery(i , j + 1);
    }
}

void lessQuery(ll i , ll j)
{
    compare[i][j] = query(a + t - 1 , b + t - 1);
    if(compare[i][j] == -1)
    {
        bitA[i] = 0;
        bitB[i] = 1;
        b += t;
    }
    else
    {
        equalQuery(i , j + 1);
    }
}

int main() {
    fast_io;
    set_random;
    bitA[30] = 1;
    bitB[30] = 2;

    for(ll i = 29 ; i >= 0 ; i--)
    {
        t = (1 << i);
        if(bitA[i + 1] == bitB[i + 1])  compare[i][0] = compare[i + 1][0];
        else                            compare[i][0] = query(a , b);

        if(compare[i][0] == 0)
        {
            equalQuery(i , 1);
        }
        else if(compare[i][0] == 1)
        {
            greaterQuery(i , 1);
        }
        else if(compare[i][0] == -1)
        {
            lessQuery(i , 1);
        }
    }
    cout << "! " << a << sep << b << endl;

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