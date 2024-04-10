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

inline string to_str(int x)
{
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

void q1()
{
    int n,k;
    cin >> n >> k;

    vector<pii> a(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;

        a[i]=Mp(x,y);
    }

    Sort(a);
    ll j=0 , sum=0 ,ans=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && a[j].X-a[i].X<k)
        {
            sum+=a[j++].Y;
        }
        ans=max(ans,sum);
        sum-=a[i].Y;
    }

    cout << ans << endl;
}

void q2()
{
    string s;
    cin >> s;

    int ans=8;

    if(s[0]=='a' || s[0]=='h')
    {
        ans-=3;
    }
    if(s[1]=='1' || s[1]=='8')
    {
        ans-=3;
    }

    cout << (ans==2 ? ans+1 : ans);
}

void q3()
{
    int n , ans=0;
    cin >> n;

    vector<int> a(--n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int x,y;
    cin >> x >> y;

    for(int i=x-1;i<y-1;i++)
    {
        ans+=a[i];
    }

    cout << ans << endl;
}

void q4()
{
    int n , k;
    cin >> n >> k;

    int maxn=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        if(k%t==0 && t>maxn)
        {
            maxn=t;
        }
    }

    cout << k/maxn;
}

int main()
{
    q2();
    return 0;
}