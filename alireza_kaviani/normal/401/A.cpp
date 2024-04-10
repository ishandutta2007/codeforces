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

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(abs(i-j)%2==0)
            {
                cout << "C";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}

void q4()
{
    int n;
    cin >> n;

    int p=0;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        h[i]=p-t;
        p=t;
    }

    int ans=0;
    int t=0;
    for(int i=0;i<n;i++)
    {
        t+=h[i];
        ans=min(ans,t);
    }

    cout << abs(ans) << endl;
}

int main()
{
    q2();
    return 0;
}