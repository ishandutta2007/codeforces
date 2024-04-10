#include <bits/stdc++.h>

#define fin freopen("input.txt", "r", stdin)
#define fout freopen("output.txt", "w", stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tin int timer=clock()
#define tout printf(I,clock()-timer)
#define sqr(x) (x)*(x)
#define elif else if
#define maxint 2147483647
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define L "%lld"
#define LL "%lld%lld"
#define LLL "%lld%lld%lld"
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

ll n,maxi,sum,zn;

int main()
{
    fast;
    //mini=maxint;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>zn;
        maxi=max(maxi,zn);
        sum+=zn;
        //mini=min(mini,zn);
    }
    ll l=1,r=(int)1e13;
    while (r-l>1)
        if (2*maxi<(r+l)/2+sum) r=(r+l)/2; else l=(r+l)/2;
    if (2*maxi<l+sum) cout<<l; else cout<<r;
    return 0;
}