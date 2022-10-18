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
const ld eps=1e-10;

///---program start---///

main()
{
    int n;
    cin>>n;
    set<int> setik;
    setik.clear();
    while (n--)
    {
        int zn;
        scanf("%d",&zn);
        setik.insert(zn);
    }
    if (setik.size()==1||setik.size()==2) return cout<<"YES", 0;
    if (setik.size()!=3) return cout<<"NO", 0;
    vector<int> setik_(all(setik));
    if ((0.0+setik_[2]+setik_[0])/2==setik_[1]) cout<<"YES";
    else cout<<"NO";
}