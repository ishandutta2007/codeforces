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
    double l,p,q;
    cin >> l >> p >> q;

    cout << p*(l/(p+q)) << endl;
}

void q2()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int ans=0,ans2=0;
    for(int i=0;i<=n/2;i++)
    {
        ans+=a[i];
        ans2+=a[n-i-1];

        if(n%2==1 && i==n/2)
        {
            ans-=a[i];
        }
    }

    cout << ans2 << ends << ans << endl;
}

void q3()
{
    int n;
    cin >> n;

    string s[]={"0","1","2","3","4","5","6","7","8","9"};
    for(int i=1;n!=0;i++)
    {
        string y="";
        int x=i;
        while(x!=0)
        {
            y=s[x%10]+y;
            x/=10;
        }

        if(y.size()>=n)
        {
            cout << y[n-1] << endl;
            n=0;
        }
        else
        {
            n-=y.size();
        }
    }
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