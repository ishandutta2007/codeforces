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
    int n,k;
    cin>>n>>k;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int p=0;
    while (p<a.size()&&a[p]>=0)
        p++;
    if (p==a.size()) return cout<<0, 0;
    int cnt_minus=0;
    for (auto i:a)
        cnt_minus+=(i<0);
    if (cnt_minus>k) return cout<<-1, 0;
    #define oryshych roman_kaban
    vi oryshych;
    oryshych.clear();
    int cur=n-p;
    for (;p<a.size();)
    {
        int j;
        for (j=p+1;j<a.size()&&a[j]>=0;)
            j++;
        oryshych.pb(j-p-1);
        p=j;
    }
    //cout<<"oryshych ::\n";
    //for (auto i:oryshych)
      //  cout<<i<<" ";
    //cout<<"\n";
    int rem_last=oryshych.back();
    oryshych.pop_back();
    sort(all(oryshych));
    int ans=1;
    while (cur>k)
    {
        if (cur-rem_last<=k) return cout<<ans+1, 0;
        if (oryshych.empty()) break;
        ans+=2;
        cur-=oryshych.back();
        oryshych.pop_back();
    }
    //cout<<"cur :: "<<cur<<"\n";
    if (cur>k) return cout<<-1, 0;
    cout<<ans;
}