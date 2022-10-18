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
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

char a[ar][ar];

main()
{
    memset(a,'1',sizeof(a));
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int cnt=0;
            cnt+=(a[i-1][j]=='o');
            cnt+=(a[i+1][j]=='o');
            cnt+=(a[i][j-1]=='o');
            cnt+=(a[i][j+1]=='o');
            if (cnt%2!=0) return cout<<"NO", 0;
        }
    cout<<"YES";
}