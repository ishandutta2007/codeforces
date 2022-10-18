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

#define int ll

main()
{
    int n,st;
    cin>>n>>st;
    vector<int> a;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    if (n==1) return cout<<0, 0;
    sort(all(a));
    if (st<=a[0]) return cout<<a[a.size()-2]-st, 0;
    if (st>=a.back()) return cout<<st-a[1], 0;
    int ans1;
    int ans2;
    if (st>a[a.size()-2]) ans1=st-a[0], ans2=ans1;
    else ans1=st-a[0]+a[a.size()-2]-a[0], ans2=a[a.size()-2]-st+a[a.size()-2]-a[0];
    int ans3;
    int ans4;
    if (st<a[1]) ans3=a.back()-st, ans4=ans3;
    else ans3=a.back()-st+a.back()-a[1], ans4=st-a[1]+a.back()-a[1];
    //cout<<ans1<<" "<<ans2<<"\n";
    cout<<min(ans1,min(ans2,min(ans3,ans4)));
}