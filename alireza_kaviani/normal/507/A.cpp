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
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '

int main()
{
    int n,k;
    cin >> n >> k;

    vector<pii> p;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        p.push_back(Mp(t,i+1));
    }
    Sort(p);

    vector<int> a;
    int i=0;
    int ans=0;
    while(k>=ans+p[i].X && i<n)
    {
        ans+=p[i].X;
        a.push_back(p[i].Y);
        i++;
    }
    cout << i << endl;
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << ends;
    }

    return 0;
}