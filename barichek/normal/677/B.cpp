#include <bits/stdc++.h>

#define fin freopen("basketball.in","r",stdin)
#define fout freopen("basketball.out","w",stdout)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
//#define fir first
//#define sec second

#ifdef WIN32
    #define L "%I64d"
#else
    #define L "%lld"
#endif

using namespace std;


typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const ll md=1e9+7;
const ld eps=1e-6;

inline void read(int &n)
{
    n=0;
    char c='0';
    bool minus=false;
    while (!feof(stdin))
    {
        c=getchar();
        if (c==' '||c=='\n') break;
        if (c=='-') minus=true;
        else n=n*10+c-'0';
    }
    if (minus) n*=-1;
}

inline void write(int n)
{
    if (n==0)
    {
        putchar('0');
        return;
    }
    char ans[100];
    int kil=0;
    if (n<0) putchar('-');
    n=abs(n);
    while (n)
    {
        ans[kil++]=char(n%10+'0');
        n/=10;
    }
    for (int i=kil-1;i>=0;i--)
        putchar(ans[i]);
}

int main()
{
    int n,h,k,a[100000];
    scanf(III,&n,&h,&k);
    for (int i=0;i<n;i++)
        scanf(I,&a[i]);
    ll ukaz=0,ans=0,ost=0;
    for (int i=0;i<n;i++)
    {
        //cout<<i<<" "<<ost<<" "<<a[i]<<"\n";
        if (ost+a[i]>h) ans++,ost=0;
        ans+=(ost+a[i])/k;
        ost=(ost+a[i])%k;
    }
    if (ost) ans+=ost/k+(ost%k>0);
    cout<<ans;
    return 0;
}