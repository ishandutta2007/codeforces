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
    map<char,int> mp2;

    mp2['B']=1;mp2['u']=2;mp2['l']=1;mp2['b']=1;mp2['a']=2;mp2['s']=1;mp2['r']=1;

    string s , s2="Bulbasaur";
    cin >> s;

    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }

    int ans=s.size();
    for(int i=0;i<s2.size();i++)
    {
        int t=mp[s2[i]]/mp2[s2[i]];
        ans=min(ans,t);
    }
    cout << ans << endl;
}

void q3()
{
    int n , e=0 , o=0;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;

        if(t%2)
        {
            o++;
        }
        else
        {
            e++;
        }
    }
    cout << min(e,o) << endl;
}

void q4()
{
    int n=5 , sum=0 , m=0;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    Sort(a);
    for(int i=0;i<n;i++)
    {
        int s=0;
        if(i!=n)
        {
            if(a[i]==a[i+1])
            {
                s=a[i]+a[i+1];
            }
        }
        if(i<n-1)
        {
            if(a[i]==a[i+2])
            {
                s+=a[i+2];
            }
        }
        m=max(m,s);
    }

    cout << sum-m << endl;
}

int main()
{
    q1();
    return 0;
}