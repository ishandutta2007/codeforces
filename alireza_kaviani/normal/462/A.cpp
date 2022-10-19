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
    int n;
    cin >> n;

    string s[n];
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }

    bool b=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int t=0;
            if(j!=n-1)
            {
                if(s[i][j+1]=='o')
                {
                    t++;
                }
            }
            if(i!=n-1)
            {
                if(s[i+1][j]=='o')
                {
                    t++;
                }
            }

            if(j!=0)
            {
                if(s[i][j-1]=='o')
                {
                    t++;
                }
            }
            if(i!=0)
            {
                if(s[i-1][j]=='o')
                {
                    t++;
                }
            }

            if(t%2!=0)
            {
                b=false;
            }
        }
    }

    cout << (b?"YES":"NO");
}

void q2()
{
    double n,x,sum=0;
    cin >> n >> x;

    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        sum+=t;
    }

    sum=abs(sum);
    cout << ceil(sum/x) << endl;
}

void q3()
{
    int n;
    cin >> n;

    string s="";
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(abs(i-j)%2==0)
            {
                ans++;
                s += "C";
            }
            else
            {
                s += ".";
            }
        }
        s += "\n";
    }

    cout << ans << endl << s;
}

void q4()
{
    int n;
    cin >> n;

    int mini=0 , maxi=0 , a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>a[maxi])
        {
            maxi=i;
        }
        if(a[i]<a[mini])
        {
            mini=i;
        }
    }

    int t=max(maxi,mini);
    int t2=n-min(maxi,mini)-1;
    cout << max(t,t2) << endl;
}

int main()
{
    q1();
    return 0;
}