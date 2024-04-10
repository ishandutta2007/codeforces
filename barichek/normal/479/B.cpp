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
const ld eps=1e-6;

///---program start---///

int main()
{
    int n,k;
    vi a;
    cin>>n>>k;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    vector<pii> res;
    for (int i=0;i<k;i++)
    {
        if (*min_element(all(a))==*max_element(all(a)))
            break;
        ans++;
        auto it1=min_element(all(a));
        auto it2=max_element(all(a));
        res.pb(mp(it2-a.begin()+1,it1-a.begin()+1));
        (*it1)++;
        (*it2)--;
    }
    cout<<*max_element(all(a))-*min_element(all(a))<<" "<<ans<<"\n";
    for (auto i:res)
        cout<<i.fir<<" "<<i.sec<<"\n";
}