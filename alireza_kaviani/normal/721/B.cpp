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

int get(int x , int k)
{
    return (x - 1) / k * 5 + x;
}

int main()
{
    fast_io;

    int n , k , t = 1 , t2 = 0;
    cin >> n >> k;

    string s[n] , ans;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> ans;

    for(int i = 0; i < n ; i++)
    {
        if(ans.size() >= s[i].size())
        {
            if(ans.size() != s[i].size())
            {
                t++;
            }
            t2++;
        }
    }

    cout << get(t , k) << ends << get(t2 , k) << endl;

    return 0;
}