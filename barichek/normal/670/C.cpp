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

ll n,m;
map <ll,ll> kst;
struct point
{
    ll b,c,nom;
} film[200000];

bool check(point i,point j)
{
    if (kst[i.b]>kst[j.b]) return true;
    elif (kst[i.b]==kst[j.b]&&kst[i.c]>kst[j.c]) return true;
    else return false;
}

int main()
{
    fast;
    scanf("%lld",&n);
    ll x;
    for (int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        kst[x]++;
    }
    scanf("%lld",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%lld",&film[i].b);
        film[i].nom=i;
    }
    for (int i=0;i<m;i++)
        scanf("%lld",&film[i].c);
    ll ans=0;
    for (int i=0;i<m;i++)
        if (kst[film[i].b]>kst[film[ans].b]) ans=i;
        elif (kst[film[i].b]==kst[film[ans].b]&&kst[film[i].c]>kst[film[ans].c]) ans=i;
    cout<<ans+1;
    return 0;
}