#include <bits/stdc++.h>

#define fin freopen("basketball.in","r",stdin)
#define fout freopen("basketball.out","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) (x)*(x)
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
    int a,b,c;
    cin>>a>>b>>c;
    if ((b>a&&c<0)||(b<a&&c>0)) return cout<<"NO", 0;
    if (c==0) return printf((a==b)?"YES":"NO"), 0;
    printf((abs(b-a)%abs(c)==0)?"YES":"NO");
    return 0;
}