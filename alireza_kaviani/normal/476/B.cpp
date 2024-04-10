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

ll factorial(ll n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

void q1()
{
    string s,k;    cin >> s >> k;
    ll x=0,y=0 , sub=0 ,q=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+')
        {
            x++;
        }
        if(s[i]=='-')
        {
            x--;
        }

        if(k[i]=='+')
        {
            y++;
        }
        if(k[i]=='-')
        {
            y--;
        }

        if(k[i]=='?')
        {
            q++;
        }
    }

    sub=abs(x-y);
    if((q-sub)&1 || sub>q)
    {
        cout << 0 << endl;
        return;
    }
    ll t=sub+(q-sub)/2;
    ll a=q-t;

    ll fn=(ll)pow(2,q) , fs=factorial(q) / ( factorial(t) * factorial(a));
    double ans = double(fs)/double(fn);
    printf("%.10f",ans);
}

void q2()
{
    int n;cin >> n;
    cout << (n%2==0 ? (n/2-1)/2 : 0);
}

void q3()
{
    map<string,int> mp;
    int n;
    cin >> n;

    string s[n];
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        mp[s[i]]++;
    }
    int t=unique(s,s+n)-s;

    if(t==1)
    {
        cout << s[0] << endl;
    }
    else if(mp[s[0]]>mp[s[1]])
    {
        cout << s[0] << endl;
    }
    else
    {
        cout << s[1] << endl;
    }
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
    q1();
    return 0;
}