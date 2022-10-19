#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int mod = 1'000'000'007;
const int N = 200'010;
ll sum[3][N] = {};
string s;
int n, k=0;

ll pow3[N];

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

void add(int i, int x, int k)
{
    if(x == 0)
        sum[x][i] = k;
    else
        sum[x][i] = sum[x-1][i-1]*k%mod;
}

void calc_sum(int i)
{
    sum[0][i] += sum[0][i-1];
    sum[1][i] += sum[1][i-1];
    sum[2][i] += sum[2][i-1];
    sum[0][i] %= mod;
    sum[1][i] %= mod;
    sum[2][i] %= mod;
}

int main()
{
    FAST;
    cin >> n;
    cin >> s;
    pow3[0] = 1;
    Loop(i,1,N)
        pow3[i] = pow3[i-1]*3%mod;
    Loop(i,0,n)
    {
        if(s[i] == '?')
        {
            ++k;
            add(i+1, 0, 1);
            add(i+1, 1, 1);
            add(i+1, 2, 1);
        }
        else
            add(i+1,s[i]-'a',3);
        calc_sum(i+1);
    }
    if(k == 0)
        cout << modDivide(sum[2][n], 27, mod) << '\n';
    if(k == 1)
        cout << modDivide(sum[2][n], 9, mod) << '\n';
    if(k == 2)
        cout << modDivide(sum[2][n], 3, mod) << '\n';
    if(k > 2)
        cout << sum[2][n]*pow3[k-3]%mod << '\n';
    /*Loop(x,0,3){
        Loop(j,0,n+1)
            cout << sum[x][j] << ' ';
        cout << '\n';
    }*/
    //ll x = 1;
    //while(--k)
    //    x = 3*x%mod;
    //cout << (sum[2][n]%mod)*x%mod << '\n';
}