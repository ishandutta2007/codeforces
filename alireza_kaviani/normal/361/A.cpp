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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

void shift(vector<int> &vec)
{
    int x = vec[0];
    vec.erase(vec.begin());
    vec.push_back(x);
}

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    vector<int> ans(n);
    for(int i = 0 ; i < n ; i++)
    {
        if(i < k % n)   ans[i] = k / n + 1;
        else    ans[i] = k / n;
    }

    for(int i = 0 ; i < n ; i++ , cout << endl)
    {
        for(int j : ans)    cout << j << ends;
        shift(ans);
    }

    return 0;
}