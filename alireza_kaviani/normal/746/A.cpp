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
#define error(x)                    cerr << #x << " = " << x << endl;

void q1()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    Sort(a);

    bool b=false;
    for(int i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
        {
            b=true;
        }
    }

    cout << (b?"YES":"NO") << endl;
    return;
}

void q2()
{
    int a,b,c;
    cin >> a >> b >> c;

    int t=min(min(b/2,c/4),a);
    cout << t*7;
}

void q3()
{
    int n,k;
    cin >> n >> k;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int f,t;
        cin >> f >> t;

        if(t>k)
        {
            ans=max(ans,f-(t-k));
        }
        else
        {
            ans=max(ans,f);
        }
    }
    cout << ans << endl;
}

void q4()
{
    string s;
    cin >> s;

    int t=0;
    bool b=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='4')
        {
            t++;
        }
        else
        {
            t=0;
        }

        if(s[i]!='1' && s[i]!='4' || t>2)
        {
            b=false;
        }
    }
    cout << (b?"YES":"NO");
}

int main()
{
    q2();
    return 0;
}