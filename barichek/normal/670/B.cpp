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

ll n,k,a[10000000];

int main()
{
    fast;
    scanf(II,&n,&k);
    for (int i=1;i<=n;i++)
        scanf(I,&a[i]);
    ll dop=1;
    while (k>dop)
    {
        k-=dop;
        dop++;
    }
    printf(I,a[k]);
    return 0;
}