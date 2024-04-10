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

bool cmp(int a,int b)
{
    return a>b;
}

void q1()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='2')
        {
            vec.push_back(2);
        }
        if(s[i]=='3')
        {
            vec.push_back(3);
        }
        if(s[i]=='4')
        {
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(3);
        }
        if(s[i]=='5')
        {
            vec.push_back(5);
        }
        if(s[i]=='6')
        {
            vec.push_back(3);
            vec.push_back(5);
        }
        if(s[i]=='7')
        {
            vec.push_back(7);
        }
        if(s[i]=='8')
        {
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(7);
        }
        if(s[i]=='9')
        {
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(3);
            vec.push_back(7);
        }
    }

    sort(all(vec),cmp);
    for(int i:vec)
    {
        cout << i;
    }
}

void q2()
{
    int n,d;
    cin >> n >> d;

    int t=0;
    for(int i=0;i<d;i++)
    {
        bool ans=1;
        string s;
        cin >> s;
        for(int j=0;j<n;j++)
        {
            bool b=(s[j]=='1');
            ans=ans&b;
        }
        if(ans)
        {
            t=0;
        }
        else
        {
            t++;
        }
    }
    cout << t << endl;
}

void q3()
{
    int n,k;
    cin >> n >> k;

    int ans=-1;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;

        k-=min(8,t);
        if(k<=0)
        {
            ans=i+1;
        }
    }
    cout << ans << endl;
}

void q4()
{
    string s,k;
    cin >> s >> k;

    if(s.size()<k.size())
    {
        cout << k.size() << endl;
    }

    sort(all(s));
    sort(all(k));

    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==k[j])
        {
            j++;
        }
    }

    if(j!=k.size())
    {
        cout << k.size() << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    q1();
    return 0;
}