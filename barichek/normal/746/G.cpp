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

int a[arr];
bool lalka[arr];

main()
{
    int n,t,k;
    cin>>n>>t>>k;
    for (int i=2;i<=t+1;i++)
        cin>>a[i];
    int must_k=a[t+1];
    int max_k=a[t+1];
    for (int i=2;i<=t;i++)
        must_k+=max(0ll,a[i]-a[i+1]),
        max_k+=(a[i]-1);
    if (must_k>k||k>max_k) return cout<<-1, 0;
    k-=must_k;
    vector<pii> ans;
    vi last={1};

    int global_last=2;

    #define oryshych oryshych_kaban
    vi oryshych;
    oryshych.clear();

    for (int i=2;i<a[2]+2;i++)
        oryshych.pb(i),
        global_last++,
        ans.pb({1,i});

    for (int i=0;i<max(0ll,a[2]-a[3]);i++)
        oryshych.pop_back();

    for (int i=signed(oryshych.size())-1;i>0&&k>0;i--)
    {
        oryshych.pop_back();
        k--;
    }

    last=oryshych;

    for (int deep=2;deep<=t;deep++)
    {
        oryshych.clear();
        int rem=global_last;
        for (int i=0;i<last.size();i++)
            ans.pb({last[i],global_last++});
        for (int i=0;i<a[deep+1]-signed(last.size());i++)
            ans.pb({last.back(),global_last++});

        for (int i=rem;i<rem+a[deep+1];i++)
            oryshych.pb(i);

        for (int i=0;i<max(0ll,a[deep+1]-a[deep+2]);i++)
            oryshych.pop_back();

        for (int i=signed(oryshych.size())-1;i>0&&k>0;i--)
        {
            oryshych.pop_back();
            k--;
        }
        last=oryshych;
    }
    cout<<n<<"\n";
    for (auto i:ans)
        cout<<i.fir<<" "<<i.sec<<"\n";
}