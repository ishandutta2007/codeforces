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
    string s;
    cin >> s;
    int q=0 , q2=0 , ans=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='Q')
        {
            q++;
        }
    }

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='Q')
        {
            q2++;
        }

        if(s[i]=='A')
        {
            ans+=q2*(q-q2);
        }
    }

    cout << ans << endl;
}

void q2()
{
    int n, m , ans=0;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x , y;
            cin >> x >> y;

            if(x || y)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

void q3()
{
    string s , s2="";
    cin >> s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='0' || s2.size()!=i)
        {
            s2+=s[i];
        }
    }

    if(s2==s)s2.pop_back();
    cout << s2 << endl;
}

void q4()
{
    int n;
    cin >> n;

    int m[n];
    m[n-1]=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    for(int i=n-2;i>=0;i--)
    {
        m[i]=max(m[i+1],a[i+1]);
    }

    for(int i=0;i<n;i++)
    {
        cout << max(0 , m[i]+1-a[i]) << ends;
    }
}

int main()
{
    q4();
    return 0;
}