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

template<class t>
void operator>>(istream &in , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cin >> vec[i];
    }
}
template<class t>
void operator << (ostream &out , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cout << vec[i];
    }
}

int main()
{
    fast_io;

    int n , k , ans = 0;
    cin >> n >> k;

    for(int i = 0 ;i < n ; i++)
    {
        int x;
        cin >> x;
        ans += x / k + (x % k == 0 ? 0 : 1);
    }
    cout << ans / 2 + ans % 2 << endl;

    return 0;
}