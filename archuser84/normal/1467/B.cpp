#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

int a[300'010];
int n;

int solve(int i, int x)
{
    int pr = 0, ne = 0;
    if(0 <= i-2 && i   < n) pr += (a[i-1] > a[i-2] && a[i-1] > a[i  ]) || (a[i-1] < a[i-2] && a[i-1] < a[i  ]);
    if(0 <= i-1 && i+1 < n) pr += (a[i  ] > a[i-1] && a[i  ] > a[i+1]) || (a[i  ] < a[i-1] && a[i  ] < a[i+1]);
    if(0 <= i   && i+2 < n) pr += (a[i+1] > a[i  ] && a[i+1] > a[i+2]) || (a[i+1] < a[i  ] && a[i+1] < a[i+2]);
    swap(a[i], x);
    if(0 <= i-2 && i   < n) ne += (a[i-1] > a[i-2] && a[i-1] > a[i  ]) || (a[i-1] < a[i-2] && a[i-1] < a[i  ]);
    if(0 <= i-1 && i+1 < n) ne += (a[i  ] > a[i-1] && a[i  ] > a[i+1]) || (a[i  ] < a[i-1] && a[i  ] < a[i+1]);
    if(0 <= i   && i+2 < n) ne += (a[i+1] > a[i  ] && a[i+1] > a[i+2]) || (a[i+1] < a[i  ] && a[i+1] < a[i+2]);
    swap(a[i], x);
    return ne - pr;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        //int n;
        cin >> n;
        //vector<int> a(n);
        Loop(i,0,n) cin >> a[i];
        int cnt=0;
        int ans = 0;
        if(n < 3) {cout << "0\n"; continue;}
        Loop(i,1,n-1)
        {
            ans = min({ans, solve(i,  1e9 + 10),
                            solve(i, a[i+1]),
                            solve(i, a[i  ]),
                            solve(i, a[i-1]),
                            solve(i, -1e9 - 10)});
            if((a[i] > a[i-1] && a[i] > a[i+1]) ||
               (a[i] < a[i-1] && a[i] < a[i+1])){
                cnt++;
            }
        }
        ans = min({ans, solve(0,  1e9 + 10)
                      , solve(0, a[1])
                      , solve(0, a[0])
                      , solve(0, -1e9 - 10)});
        ans = min({ans, solve(n-1,  1e9 + 10)
                      , solve(n-1, a[n-1])
                      , solve(n-1, a[n-2])
                      , solve(n-1, -1e9 - 10)});
        cout << cnt + ans << '\n';
    }
}