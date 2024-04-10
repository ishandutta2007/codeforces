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
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    vector<int> cnt(1005,0);
    set<int> a;
    int n;
    cin >> n;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        cnt[t]++;
        ans=max(ans,cnt[t]);

        a.insert(t);
    }
    cout << ans << ends << a.size();

    return 0;
}