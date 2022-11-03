#include <bits/stdc++.h>

#define fin freopen("basketball.in","r",stdin)
#define fout freopen("basketball.out","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

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

int main()
{
ll n,h,k,a[100000];
cin>>n>>h>>k;
for (int i=0;i<n;i++)
cin>>a[i];
ll ukaz=0,ans=0,ost=0;
for (int i=0;i<n;i++)
{
//couti" "ost" "a[i]"\n";
if (ost+a[i]>h) ans++,ost=0;
ans+=(ost+a[i])/k;
ost=(ost+a[i])%k;
}
if (ost) ans+=ost/k+(ost%k>0);
cout<<ans;
return 0;
}