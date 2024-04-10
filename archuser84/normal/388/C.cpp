///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> v;
    int x[2] = {};
    while(n--)
    {
        int k;
        cin >> k;
        Loop(i,0,k)
        {
            int z;
            cin >> z;
            if(2*i < k-1) x[0] += z;
            if(2*i == k-1) v.push_back(z);
            if(2*i > k-1) x[1] += z;
        }
    }
    sort(all(v)); reverse(all(v));
    Loop(i,0,v.size()) x[i&1] += v[i];
    cout << x[0] << ' ' << x[1] << '\n';
}