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
    int n,m;
    cin >> n >> m;

    int s=6-max(n,m)+1;
    int t=6;
    if(s%3==0)
    {
        s/=3;
        t/=3;
    }
    if(s%2==0)
    {
        s/=2;
        t/=2;
    }

    cout << s << "/" << t << endl;
}

void q2()
{
    string ans[]={"chest","biceps","back"};

    int n , a[]={0,0,0};
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        a[i%3]+=t;
    }

    int mi=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]>a[mi])
        {
            mi=i;
        }
    }
    cout << ans[mi] << endl;
}

void q3()
{
    ll n, ans=0;
    cin >> n;

    ll j=9;
    for(ll i=1;n!=0;i++)
    {
        ll t=min(n,j);
        ans+=t*i;

        n-=t;
        j*=10;
    }
    cout << ans << endl;
}

void q4()
{
    int n;
    cin >> n;

    int p=0;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        h[i]=p-t;
        p=t;
    }

    int ans=0;
    int t=0;
    for(int i=0;i<n;i++)
    {
        t+=h[i];
        ans=min(ans,t);
    }

    cout << abs(ans) << endl;
}

int main()
{
    q1();
    return 0;
}