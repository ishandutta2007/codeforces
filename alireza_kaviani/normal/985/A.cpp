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

int main()
{
    int n , ans = 0 , ans2 = 0;
    cin >> n;

    vector<int> a(n / 2);
    for(int i = 0 ;i < n / 2; i++)
    {
        cin >> a[i];
    }

    Sort(a);
    vector<bool> see(n + 10 , false);
    for(int i = 0 ; i < n / 2 ; i++)
    {
        ans += abs(a[i] - (i * 2 + 1));
        ans2 += abs(a[i] - (i * 2 + 2));
    }
    cout << min(ans , ans2) << endl;

    return 0;
}