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

    int a[n],b[n] , t1=0 , t2=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        t1+=a[i];
        t2+=b[i];
    }

    int ans=abs(t1-t2) , ans_ind=0;
    for(int i=0;i<n;i++)
    {
        t1-=a[i];
        t1+=b[i];
        t2-=b[i];
        t2+=a[i];

        if(abs(t1-t2)>ans)
        {
            ans=abs(t1-t2);
            ans_ind=i+1;
        }

        t1+=a[i];
        t1-=b[i];
        t2+=b[i];
        t2-=a[i];
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

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]-a[i+1]>ans)
        {
            ans=a[i]-a[i+1];
        }
    }

    cout << max(0,ans - c) << endl;
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
    q3();
    return 0;
}