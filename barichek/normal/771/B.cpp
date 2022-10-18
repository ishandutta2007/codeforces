#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

bool a[arr];
string ans[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    vector<string> use(0);
    for (char i='a';i<='z';i++)
        use.pb("A"+string(1,i)),
        use.pb("B"+string(1,i));
    int n,k;
    cin>>n>>k;
    for (int i=k;i<=n;i++)
    {
        string s;
        cin>>s;
        a[i]=s[0]=='N';
    }
    if (a[k])
        ans[1]=ans[2]=use.back(),
        use.pop_back();
    else
        ans[1]=use.back(),
        use.pop_back(),
        ans[2]=use.back(),
        use.pop_back();
    for (int i=3;i<=k;i++)
        ans[i]=use.back(),
        use.pop_back();
    for (int i=k+1;i<=n;i++)
        if (a[i])
            ans[i]=ans[i-k+1];
        else
            ans[i]=use.back(),
            use.pop_back();
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}