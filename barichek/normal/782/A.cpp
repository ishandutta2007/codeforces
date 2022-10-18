#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define files_ds(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    fast;
    int n;
    cin>>n;
    set<int> s;
    s.clear();
    n*=2;
    int cur=0;
    int ans=0;
    while (n--)
    {
        int val;
        cin>>val;
        if (s.count(val))
            s.erase(val),
            cur--;
        else
            s.insert(val),
            cur++;
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
}