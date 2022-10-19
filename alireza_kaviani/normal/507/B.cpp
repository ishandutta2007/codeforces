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

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    Sort(a);
    int b=0;
    for(int i=1;i<n;i++)
    {
        b=max(b,(a[i]==a[i-1]?1:0));
    }

    cout << (b?"Yes":"No") << endl;
}

void q2()
{
    int t,s,x;
    cin >> t >> s >> x;

    x-=t;
    if(x>=0 && x%s<=1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

void q3()
{
    ld r , x , y , x1 , y1;
    cin >> r >> x >> y >> x1 >> y1;

    ld m=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));

    int ans = int(m) / (2*r);
    if(floor(m)!=ceil(m) || int(m) % int(2*r)!=0)
    {
        ans++;
    }
    cout << ans << endl;
}

void q4()
{
    int n,m;
    cin >> n >> m;

    int t=n-m , k=m-1 , ans=(t>k?m+1:k);
    cout << ans << endl;
}

int main()
{
    q3();
    return 0;
}