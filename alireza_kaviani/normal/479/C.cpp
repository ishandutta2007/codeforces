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

int main()
{
    int n;
    cin >> n;

    vector<pii> p;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        p.push_back(Mp(a,b));
    }
    Sort(p);
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].Y>=s)
        {
            s=p[i].Y;
        }
        else
        {
            s=p[i].X;
        }
    }
    cout << s << endl;

    return 0;
}