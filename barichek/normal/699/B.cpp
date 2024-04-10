#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int a1[1000];
int a2[1000];

int main()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int all=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='*') a1[i]++, a2[j]++, all++;
        }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a1[i]+a2[j]-(a[i][j]=='*')==all)
                return cout<<"YES\n"<<i+1<<" "<<j+1<<"\n", 0;
    cout<<"NO";
}