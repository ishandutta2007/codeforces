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

            if((x&&y)==false)
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
    string s;   cin >> s;
    int ans=1;

    for(int i=0;i<s.size();i++)
    {
        ans=ans*2+(s[i]=='7');
    }
    cout << ans-1 << endl;
}

int main()
{
    q3();
    return 0;
}