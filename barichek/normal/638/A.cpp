#include <bits/stdc++.h>

#define fin freopen("input.txt", "r", stdin)
#define fout freopen("output.txt", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tin int timer=clock()
#define tout printf(I,clock()-timer)
#define sqr(x) (x)*(x)
#define elif else if
#define maxint 2147483647
#define pi M_PI
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define L "%lld"
#define LL "%lld%lld"
#define LLL "%lld%lld%lld"
#define D "%lf"
#define DD "%lf%lf"
#define DDD "%lf%lf%lf"
#define mp make_pair
#define pb push_back
#define sec second
#define fir first

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;

int n,a;

int main()
{
    fast;
    scanf(II,&n,&a);
    if (a%2) cout<<a/2+1;
    else cout<<(n-a)/2+1;
    return 0;
}