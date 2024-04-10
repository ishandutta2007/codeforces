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

map<char,int> mp;
void q1()
{
    string s;
    int n,m;
    cin >> n >> m >> s;

    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }

    bool b=true;
    for(int i=0;i<s.size();i++)
    {
        if(mp[s[i]]>m)
        {
            b=false;
        }
    }

    cout << (b?"YES":"NO");
}

void q2()
{
    string y[]={"","one","two","three","four","five","six","seven","eight","nine"};
    string yd[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string d[]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    int n;
    cin >> n;
    if(n==0)
    {
        cout << "zero";
    }
    else if(n/10==1)
    {
        cout << yd[n%10];
    }
    else if(n/10==0)
    {
        cout << y[n];
    }
    else
    {
        cout << d[n/10] << (n%10!=0?"-":"") << y[n%10];
    }
}

void q3()
{
    string s;
    cin >> s;

    int n=s.size() , sw=-1;
    for(int i=n-1;i>=0;i--)
    {
        if((s[i]-'0')%2==0 && (s[n-1]>s[i] || sw==-1))
        {
            sw=i;
        }
    }

    if(sw!=-1)
    {
        swap(s[n-1],s[sw]);
        cout << s << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

void q4()
{
    string s;   cin >> s;
    int ans=1;

    for(int i=0;i<s.size();i++)
    {
        ans=ans*2-(s[i]=='4');
    }
    cout << ans << endl;
}

int main()
{
    q3();
    return 0;
}