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

    for(int i=n/2;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout << '*';
        }

        for(int j=0;j<(n/2-i)*2+1;j++)
        {
            cout << 'D';
        }

        for(int j=0;j<i;j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for(int i=1;i<=n/2;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout << '*';
        }

        for(int j=0;j<(n/2-i)*2+1;j++)
        {
            cout << 'D';
        }

        for(int j=0;j<i;j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

void q2()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin >> vec[i];
    }
    Sort(vec);

    int now=0 , ans=0;
    for(int i=0;i<n;i++)
    {
        now+=vec[i];
        while(vec[i+1]<now)
        {
            i++;
        }
        ans++;
    }
    cout << ans << endl;
}

void q3()
{
    int n;
    cin >> n;

    bool ans=false;
    for(int i=0;i<n;i++)
    {
        int a,b;
        string s;
        cin >> s >> a >> b;

        if(a>=2400 && a<b)
        {
            ans=true;
        }
    }

    if(ans)
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
    q4();
    return 0;
}