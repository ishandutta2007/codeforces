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
    int a,b;
    cin >> a >> b;

    int w1=0,w2=0,d;
    for(int i=1;i<=6;i++)
    {
        int s=abs(a-i);
        int t=abs(b-i);

        if(s<t)
        {
            w1++;
        }
        if(s==t)
        {
            d++;
        }
        if(s>t)
        {
            w2++;
        }
    }

    cout << w1 << ends << w2 << ends << d << endl;
}

void q2()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        ll s=n*(n+1)/2;
        ll s2=(pow(2,floor(log2(n))+1)-1)*2;

        cout << s-s2 << endl;
    }
}

void q3()
{
    int na , nb , k , m;
    cin >> na >> nb >> k >> m;

    int maxa=0;
    int minb=0;
    vector<int> a(na),b(nb);

    for(int i=0;i<a.size();i++)
    {
        cin >> a[i];
        if(i==k-1)
        {
            maxa=a[i];
        }
    }
    for(int i=0;i<b.size();i++)
    {
        cin >> b[i];
        if(i==nb-m)
        {
            minb=b[i];
        }
    }

    if(maxa<minb)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

void q4()
{
    string s , s2;
    cin >> s;
    s2=s;
    reverse(all(s2));

    int d=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s2[i])
        {
            d++;
        }
    }
    if(d==2 || (s.size()%2==1) && d==0)
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