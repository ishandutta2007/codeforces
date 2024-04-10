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

const int N = 100'010;
deque<int> d;
int A[2*N], B[2*N];
int n;

int main()
{
    FAST;
    cin >> n;
    int q;
    cin >> q;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }
    Loop(i,0,2*n-2)
    {
        int x = A[i] = d.front();
        d.pop_front();
        int y = B[i] = d.front();
        d.pop_front();
        if(x < y)
            swap(x, y);
        d.push_front(x);
        d.push_back(y);
    }
    while(q--)
    {
        ll x;
        cin >> x; x--;
        if(x >= 2*n-2)
        {
            x %= n-1;
            x += n-1;
        }
        cout << A[x] << ' ' << B[x] << '\n';
    }
}