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
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    a=max(3*a/10,a-a/250*c);
    b=max(3*b/10,b-b/250*d);

    if(a>b)
    {
        cout << "Misha" << endl;
    }
    if(a==b)
    {
        cout << "Tie" << endl;
    }
    if(a<b)
    {
        cout << "Vasya" << endl;
    }
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
    q4();
    return 0;
}