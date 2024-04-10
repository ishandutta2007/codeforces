#include <bits/stdc++.h>

#define fin freopen("gold.in", "r", stdin)
#define fout freopen("gold.out", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) (x)*(x)
#define elif else if
#define maxint 2147483647
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

ll n,k,a[100000],b[100000],suma,sumb;

bool can(ll key)
{
    ll nowk=k;
    if ((ld)sumb+k<(ld)suma*key) return false;
    for (int i=0;i<n;i++)
        if (b[i]/a[i]<key) nowk-=a[i]*key-b[i];
    if (nowk<0) return false;
    else return true;
}

int main()
{
    fast;
    scanf("%lld%lld",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        suma+=a[i];
    }
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
        sumb+=b[i];
    }
    ll l=0,r=(ll)1e15;
    //cout<<sumb<<" "<<suma<<" "<<k<<"\n";
    //cout<<l<<" "<<(l+r)/2<<" "<<r<<"\n";
    while (r-l>1)
    {
        if (can((l+r)/2)) l=(l+r)/2; else r=(l+r)/2;
        //cout<<l<<" "<<(l+r)/2<<" "<<r<<"\n";
    }
    if (can(r)) cout<<r;
    else cout<<l;
    //cout<<"\n"<<can((ll)2e9);
    return 0;
}