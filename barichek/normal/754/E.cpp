#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

string a[400];
string b[400];

short int z[400][400][801];

bool equal_(const char &a,const char &b)
{
    if (a=='?') return true;
    return a==b;
}

void build_z_f(string s,int xx,int yy)
{
    for (int i=1,l=0,r=0;i<s.length();i++)
    {
        z[xx][yy][i]=0;
        if (i<=r)
            z[xx][yy][i]=min((short int)(r-i+1),z[xx][yy][i-l]);
        while (i+signed(z[xx][yy][i])<s.length()&&equal_(s[z[xx][yy][i]],s[i+signed(z[xx][yy][i])]))
            z[xx][yy][i]++;
        if (i+z[xx][yy][i]-1>r)
            r=i+z[xx][yy][i]-1,
            l=i;
    }
}

main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        while (a[i].length()<800)
            a[i]+=a[i];
        a[i]=a[i].substr(0,800);
    }
    int r,c;
    cin>>r>>c;
    for (int i=0;i<r;i++)
        cin>>b[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<r;j++)
            build_z_f(b[j]+a[i],i,j);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            bool ok=true;
            for (int k=0;k<r;k++)
                ok&=z[(i+k+n)%n][k][j+c]>=c;
            cout<<ok;
        }
        cout<<"\n";
    }
}