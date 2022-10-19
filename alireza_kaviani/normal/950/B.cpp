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

int main()
{
    ll n,m;
    cin >> n >> m;

    vector<ll> x(n) , y(m);
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> y[i];
    }

    bool b=true;
    ll i=0 , j=0 , ans=0 , s1=0 , s2 = 0 ;
    while(i < n || j < m)
    {
        if(b)
        {
            s1=x[i];
            s2=y[j];
            i++;
            j++;
        }
        if(s1 == s2)
        {
            ans++;
            b=true;
        }
        else if(s1 > s2 && j<m)
        {
            s2+=y[j];
            j++;
            b=false;
        }
        else if(s1 < s2 && i<n)
        {
            s1+=x[i];
            i++;
            b=false;
        }
    }
    if(s1 == s2 && b==false)
    {
        ans++;
    }
    cout << ans << endl;

    return 0;
}