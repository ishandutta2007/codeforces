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

bool cnt[arr];

main()
{
    int n,s;
    cin>>n>>s;
    vi a;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int root_is=a[--s];
    n--;
    a.erase(a.begin()+s);
    sort(all(a));
    int ukaz=0;
    int cur_cnt=0;
    int all_had=1;
    int ans=maxint;
    cnt[0]=true;
    int cnt0=0;
    for (auto i:a)
        cnt0+=(i==0);
    //cout<<"cnt0 :: "<<cnt0<<"\n";
    all_had+=cnt0;
    for (int deep=0;deep<=n;deep++)
    {
        while (ukaz<n&&a[ukaz]<=deep)
        {
            if (cnt[a[ukaz]])
                cur_cnt++;
            else
                cnt[a[ukaz]]=true,
                all_had++;
            ukaz++;
        }
        int cur=0;
        int must_down=n-ukaz;//+(root_is>0);
        //cout<<deep<<" :: must_down :: "<<must_down<<"\n";
        //cout<<deep<<" :: all_had :: "<<all_had<<"\n";
        cur=must_down+((deep+1-(all_had+must_down))>0?(deep+1-(all_had+must_down)):0)+cnt0+(root_is>0);
        //cout<<deep<<" :: "<<cur<<"\n";
        ans=min(ans,cur);
    }
    cout<<ans;
}