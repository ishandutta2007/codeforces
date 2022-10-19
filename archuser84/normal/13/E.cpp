#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 100'010;
const int S = 310;
int a[N];
int nxt[N], cnt[N];
int n;

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    Loop(i,0,n) cin >> a[i];
    LoopR(i,0,n)
    {
        nxt[i] = i/S < (i+a[i])/S || i+a[i] >= n? i+a[i]: nxt[i+a[i]];
        cnt[i] = i/S < (i+a[i])/S || i+a[i] >= n? 1: cnt[i+a[i]] + 1;
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 0)
        {
            int j, x;
            cin >> j >> x; j--;
            a[j] = x;
            LoopR(i,0,j+1)
            {
                nxt[i] = i/S < (i+a[i])/S || i+a[i] >= n? i+a[i]: nxt[i+a[i]];
                cnt[i] = i/S < (i+a[i])/S || i+a[i] >= n? 1: cnt[i+a[i]] + 1;
                if(i%S == 0) break;
            }
        }
        else
        {
            int i;
            cin >> i; i--;
            int ans = 0, ind;
            while(nxt[i] < n)
            {
                ans += cnt[i];
                i = nxt[i];
            }
            while(i < n)
            {
                ind = i;
                ++ans;
                i = i+a[i];
            }
            cout << ind+1 << ' '<< ans << '\n';
        }
    }
}