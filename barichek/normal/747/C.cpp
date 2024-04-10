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
#define int long long

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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int will_open[arr];

main()
{
    fast;
    int n,q;
    cin>>n>>q;
    while (q--)
    {
        int t,k,d;
        cin>>t>>k>>d;
        int cnt_open=0;
        for (int i=1;i<=n;i++)
            cnt_open+=will_open[i]<=t;
        if (cnt_open<k)
        {
            cout<<-1<<"\n";
            continue;
        }
        int sum=0;
        for (int i=1;i<=n&&k>0;i++)
            if (will_open[i]<=t)
                will_open[i]=t+d,
                sum+=i,
                k--;
        cout<<sum<<"\n";
    }
}