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

map<pair<ld,ld>,int> cnt;

int c_n_2(int n)
{
    return n*(n-1)/2;
}

main()
{
    int n;
    cin>>n;
    vector<pii> a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i.fir>>i.sec;
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
            cnt[mp((a[i].fir+a[j].fir)/2.0,(a[i].sec+a[j].sec)/2.0)]++;
    int ans=0;
    for (auto i:cnt)
        ans+=c_n_2(i.sec);
    cout<<ans;
}