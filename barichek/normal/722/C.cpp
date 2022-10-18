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
    fast;
    #define int ll
    int n;
    cin>>n;
    vector<ll> a;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    vector<ll> pref;
    pref.clear();
    pref.pb(0);
    pref.pb(a.front());
    for (int i=1;i<a.size();i++)
        pref.pb(pref.back()+a[i]);
    pref.pb(pref.back());
    set<int> del;
    del.clear();
    del.insert(0);
    del.insert(n+1);
    multiset<ll> sums;
    sums.clear();
    sums.insert(pref.back());
    for (int i=0;i<n;i++)
    {
        int now;
        cin>>now;
        auto it2=del.upper_bound(now);
        auto it1=it2;
        it1--;
        //cout<<i<<" "<<*it1<<" "<<*it2<<" !\n";
        ll cur=pref[(*it2)-1]-pref[(*it1)];
        //cout<<i<<" "<<cur<<" !\n";
        sums.erase(sums.find(cur));
        sums.insert(pref[now-1]-pref[(*it1)]);
        sums.insert(pref[(*it2)-1]-pref[now]);
        if (sums.empty()) cout<<0;
        else cout<<*sums.rbegin()<<"\n";
        del.insert(now);
    }
}