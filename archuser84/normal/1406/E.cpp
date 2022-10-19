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

vector<int> Ps;
int N = 100'010;
int S = 316;

int n;
int ans = 1;

int query(char c, int p)
{
    int ans;
    printf("%c %d\n", c, p);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int bin()
{
    int l = upper_bound(all(Ps), S)-Ps.begin(), r = upper_bound(all(Ps), N/ans)-Ps.begin()-1;
    if(l > r)
        return ans;
    n = query('A', 1);
    while(l < r)
    {
        int cnt = 0;
        int m = (l+r)/2;
        Loop(i,l,m+1)
        {
            cnt += query('B', Ps[i]);
        }
        int tmp = query('A', 1);
        if(n-tmp == cnt)
            l = m+1;
        else
            r = m;
        n = tmp;
    }
    if((query('B', Ps[l]), query('B', Ps[l])) == 1)
        ans *= Ps[l];
    return ans;
}

bool isPrime(int x)
{
    if(x%2 == 0)
        return x == 2;
    for(int d = 3; d*d <= x; d += 2)
        if(x%d == 0)
            return 0;
    return 1;
}

int main()
{
    scanf("%d", &N); n = N;
    S = ceil(sqrt(N));
    Loop(x,2,N+1)
    {
        if(isPrime(x))
            Ps.push_back(x);
    }
    for(int p : Ps)
    {
        if(p > S)
            break;
        if(!query('B', p))
            continue;
        int q = p;
        while(q <= N && query('A', q))
        {
            ans *= p;
            q *= p;
        }
    }
    printf("C %d\n", bin());
    fflush(stdout);
}