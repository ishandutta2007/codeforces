#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}

int main()
{
    fast_io;

    int n;
    cin >> n;

    vector<int> ans;
    while(n--)
    {
        ans.push_back(1);
        while(ans.size() > 1 && ans.back() == ans[ans.size() - 2])
        {
            ans.pop_back();
            ans.back()++;
        }
    }

    for(int i : ans)    cout << i << ends;

    return 0;
}