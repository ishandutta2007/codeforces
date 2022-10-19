#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
//#define F first
//#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = (1 << 22);
//const int logN = 24;

int a[N], b[1'000'010];

int main()
{
    FAST;
    memset(a,-1,4*N);
    int n;
    cin >> n;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        a[x] = x;
        b[i] = x;
    }
    Loop(i,0,N)
    {
        for(int j = 1; j<N; j <<= 1)
            a[i] = max(a[i], a[(i|j) - j]);
    }
    int ander = N-1;
    Loop(i,0,n)
    {
        cout << a[(~b[i])&ander] << ' ';
    }
}