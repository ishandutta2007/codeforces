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

int main()
{
    fast_io;

    int n , k , sum = 0 , now = -1;
    cin >> n >> k;

    vector<pii> vec(n);
    vector<int> ans;
    for(int i = 0 ; i < n ; i++)    vec[i] = {input() , i};

    sort(all(vec) , greater<pii>());
    for(int i = 0 ; i < k ; i++)
    {
        sum += vec[i].X;
        ans.push_back(vec[i].Y);
    }
    Sort(ans);
    cout << sum << endl;
    for(int i = 0 ; i < ans.size() ; i++)
    {
        if(i == ans.size() - 1) ans[i] = n - 1;
        cout << ans[i] - now << ends;
        now = ans[i];
    }


    return 0;
}