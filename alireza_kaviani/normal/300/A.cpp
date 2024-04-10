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

    int m;
    cin >> m;

    vector<int> z , n , p;
    for(int i = 0 ;i < m; i++)
    {
        int t;
        cin >> t;
        if(t == 0)z.push_back(t);
        if(t < 0)n.push_back(t);
        if(t > 0)p.push_back(t);
    }

    if(n.size() % 2 == 0)
    {
        z.push_back(n[n.size() - 1]);
        n.pop_back();
    }

    if(p.size() == 0)
    {
        cout << n.size() - 2 << ends;
        for(int i = 2; i < n.size() ; i++)
        {
            cout << n[i] << ends;
        }
        cout << endl << 2 << ends << n[0] << ends << n[1] << endl;
    }
    else
    {
        cout << n.size() << ends;
        for(int i : n)
        {
            cout << i << ends;
        }
        cout << endl << p.size() << ends;
        for(int i : p)
        {
            cout << i << ends;
        }
        cout << endl;
    }
    cout << z.size() << ends;
    for(int i : z)
    {
        cout << i << ends;
    }

    return 0;
}