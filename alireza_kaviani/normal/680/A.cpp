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

    int a[n],b[n] , sub=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        sub+=a[i];
        sub-=b[i];
    }

    int ans=abs(sub) , ans_ind=0;
    for(int i=0;i<n;i++)
    {
        int t=a[i]-b[i];
        t*=2;

        if((t>=0 && sub>=0) || (t<=0 && sub<=0))
        {
            int m=abs(t-sub);
            if(ans<abs(sub+m))
            {
                ans=abs(sub+m);
                ans_ind=i+1;
            }
        }
    }

    cout << ans_ind << endl;
}

void q2()
{
    int n;
    cin >> n;

    if(n%2==1)
    {
        cout << -1 << endl;
        return;
    }

    for(int i=1;i<=n/2;i++)
    {
        cout << i*2 << ends << i*2-1 << ends;
    }
}

void q3()
{
    int n , c;
    cin >> n >> c;

    int ans=-1e5;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;

        if(t-i-c>ans)
        {
            ans=t-i-c;
        }
    }

    cout << ans << endl;
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
    q4();
    return 0;
}