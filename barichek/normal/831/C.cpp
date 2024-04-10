#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define elif else if
#define int long long

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll inf=1e9+7;
const ld eps=1e-10;

///////----------big_bang----------///////

int k, n, a[2001], b[2001], pref_sum[2001], ans;
unordered_set <int> start;
unordered_map <int, bool> used;

main()
{
    fast
    cin >> k >> n;
    for(int i=0; i<k; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
        used[b[i]]=1;
    }
    pref_sum[0]=a[0];
    for(int i=1; i<k; i++)
        pref_sum[i]=pref_sum[i-1]+a[i];
    for(int i=0; i<k; i++)
    {
        start.insert(b[0]-pref_sum[i]);
    }
    while(!start.empty())
    {
        int elem=*start.begin();
        start.erase(start.begin());
        vector<int> check;
        for(int i=0; i<k; i++)
        {
            elem+=a[i];
            check.pb(elem);
        }
        sort(all(check));
        check.resize(unique(all(check))-check.begin());
        int cnt=0;
        for (auto e:check){
            if(used[e]==1)cnt++;
        }
        if(cnt==n)ans++;
    }
    cout << ans;
}