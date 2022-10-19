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
    fast_io;

    int d , s , mins = 0 , maxs = 0;
    cin >> d >> s;

    vector<pii> vec;
    for(int i = 0 ;i < d ; i++)
    {
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
        mins += x;
        maxs += y;
    }

    if(maxs < s || mins > s)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    s -= mins;
    for(int i = 0 ; i < d ; i++)
    {
        int t = min(s , vec[i].Y - vec[i].X);
        s -= t;
        cout << t + vec[i].X << ends;
    }


    return 0;
}