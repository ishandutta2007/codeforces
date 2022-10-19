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

void q1()
{
    int l,r;
    cin >> l >> r;
    cout << (l==r ? l : 2) << endl;
}

void q2()
{
    int n;cin >> n;

    for(int i=1;i<=n*n/2;i++)
    {
        cout << i << ends << n*n-i+1 << endl;
    }
}

void q3()
{
    int n , s=0 , ans=1e6;
    cin >> n;

    int a[n];
    cin >> a[0];

    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        s=max(s,a[i]-a[i-1]);
    }

    for(int i=1;i<n-1;i++)
    {
        if(a[i+1]-a[i-1]<=s)
        {
            cout << s << endl;
            return;
        }
        ans=min(ans,a[i+1]-a[i-1]);
    }

    cout << ans << endl;
}

void q4()
{
    int n, m ,k;
    cin >> n >> m >> k;

    int ans=n*10+10;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        if(t!=0 && t<=k)
        {
            ans=min(ans,abs(m-(i+1)));
        }
    }
    cout << ans*10;
}

int main()
{
    q3();
    return 0;
}