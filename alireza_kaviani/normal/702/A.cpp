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
    int s , v1 , v2 , t1 , t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int p1=v1*s+t1*2 , p2=v2*s+t2*2;

    if(p1<p2)
    {
        cout << "First" << endl;
    }
    if(p1==p2)
    {
        cout << "Friendship" << endl;
    }
    if(p1>p2)
    {
        cout << "Second" << endl;
    }
}

void q2()
{
    int n , m=2e9 , ans=1;
    cin >> n;

    int a=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;

        if(t>m)
        {
            ans++;
        }
        else
        {
            a=max(a,ans);
            ans=1;
        }
        m=t;
    }
    a=max(a,ans);
    cout << a << endl;
}

void q3()
{
    int n;
    string s;
    cin >> n >> s >> s;

    if(s=="month")
    {
        if(n==31)
        {
            cout << 7 << endl;
        }
        else if(n==30)
        {
            cout << 11 << endl;
        }
        else
        {
            cout << 12 << endl;
        }
    }

    if(s=="week")
    {
        if(n==5 || n==6)
        {
            cout << 53 << endl;
        }
        else
        {
            cout << 52 << endl;
        }
    }
}

void q4()
{
    int a,b,c;
    cin >> a >> b >> c;

    if(c==0)
    {
        cout << "YES" << endl;
    }
    else if((a-b)%c==0 && a*c<=b*c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    q2();
    return 0;
}