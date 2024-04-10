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

main()
{
    fast;
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    vi a1,a2;
    while (n--)
    {
        int val;
        string s;
        cin>>val>>s;
        if (s.front()=='U')
            a1.pb(val);
        else
            a2.pb(val);
    }
    sort(all(a1),greater<int>());
    sort(all(a2),greater<int>());
    int ans1=0;
    int ans2=0;
    while (a>0&&!a1.empty())
        a--,
        ans1++,
        ans2+=a1.back(),
        a1.pop_back();
    while (b>0&&!a2.empty())
        b--,
        ans1++,
        ans2+=a2.back(),
        a2.pop_back();
    vi all;
    for (auto i:a1)
        all.pb(i);
    for (auto i:a2)
        all.pb(i);
    sort(all(all),greater<int>());
    while (c>0&&!all.empty())
        c--,
        ans1++,
        ans2+=all.back(),
        all.pop_back();
    cout<<ans1<<" "<<ans2<<"\n";
}