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
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    fast;
    string s;
    int a,b,k;
    cin>>s>>a>>b>>k>>s;
    vi vh;
    vh.clear();
    int cur=0;
    for (int i=0;i<s.length();i++)
        if (s[i]=='1') cur=0;
        else
        {
            cur++;
            if (cur==b)
                vh.pb(i+1),
                cur=0;
        }
    vi ans;
    ans.clear();
    for (int i=0;i<int(vh.size())-a+1;i++)
        ans.pb(vh[i]);
    cout<<ans.size()<<"\n";
    for (auto i:ans)
        cout<<i<<" ";
}