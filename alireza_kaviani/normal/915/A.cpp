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

inline string to_str(int x)
{
    stringstream ss;
    string s;
    ss << x;
    ss >> s;
    return s;
}

void q1()
{
    int n , m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    Sort(a);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans=min(ans,ans+a[i]);
    }

    cout << abs(ans) << endl;
}

void q2()
{
    int n;
    cin >> n;

    vector<int> a(n) , b(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int p=0;
    for(int i=n-1 , j=0;i>=0;i-- , j++)
    {
        b[i]=p+a[i];
        p=a[i];
    }

    for(int i:b)
    {
        cout << i << ends;
    }
}

void q3()
{
    int n , ans=0;
    cin >> n;

    vector<int> a(--n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int x,y;
    cin >> x >> y;

    for(int i=x-1;i<y-1;i++)
    {
        ans+=a[i];
    }

    cout << ans << endl;
}

void q4()
{
    int n , k;
    cin >> n >> k;

    int maxn=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        if(k%t==0 && t>maxn)
        {
            maxn=t;
        }
    }

    cout << k/maxn;
}

int main()
{
    q4();
    return 0;
}