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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int fs=0,ff=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='T')
        {
            fs=i;
        }
        if(s[i]=='G')
        {
            ff=i;
        }
    }

    if(fs>ff)
    {
        swap(fs,ff);
    }
    if((ff-fs)%k!=0)
    {
        cout << "NO" << endl;return;
    }

    bool ha=true;
    for(int i=fs;i<=ff;i+=k)
    {
        if(s[i]=='#')
        {
            ha=false;
        }
    }

    if(ha)
    {
        cout << "YES" << endl;return;
    }
    else
    {
        cout << "NO" << endl;return;
    }
}

void q2()
{
    int n , a[2];
    cin >> n;

    a[0]=0;a[1]=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        a[t/5]++;
    }

    if(a[0]==0)
    {
        cout << -1 << endl; return;
    }
    if(a[1]/9==0)
    {
        cout << 0 << endl; return;
    }

    for(int i=0 ; i< (a[1]-a[1]%9) ; i++)
    {
        cout << 5;
    }
    for(int i=0;i<a[0];i++)
    {
        cout << 0;
    }
}

void q3()
{
    ll n , b , d  , sum = 0 , ans=0;
    cin >> n >> b >> d;

    for(int i = 0 ; i < n ; i++)
    {
        ll t;
        cin >> t;

        if(t <= b)
        {
            sum += t;
        }
        if(sum>d)
        {
            sum=0;
            ans++;
        }
    }

    cout << ans << endl;
}

void q4()
{
    int n , k;
    cin >> n >> k;

    vector<int> a(n) , see(n,0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    for(int i = 0 ; i < k ; i++)
    {
        see[k-i-1]=a[i];
    }

    for(int i = k ; i < n ; i++)
    {
        see[i-k]=a[i];
    }

    int ans=0;
    for(int i = 0 ; i < n ; i++)
    {
        ans+=see[i];
    }

    cout << ans << endl;
}

int main()
{
    q3();
    return 0;
}