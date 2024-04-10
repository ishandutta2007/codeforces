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

map<int,pii> cnt1;
map<int,pii> cnt2;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++)
    {
        int type,zn1,zn2;
        cin>>type>>zn1>>zn2;
        if (type==1)
            cnt1[zn1]=mp(zn2,i);
        else
            cnt2[zn1]=mp(zn2,i);
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (cnt1[i].sec>cnt2[j].sec) cout<<cnt1[i].fir<<" ";
            else cout<<cnt2[j].fir<<" ";
        cout<<"\n";
    }
}