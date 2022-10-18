#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

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

int mask[arr];
int last[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fill(last,last+arr,-1);

    string s;
    cin>>s;

    int q;
    cin>>q;
    vi vec(0);
    for (int i=0;i<q;i++){
        string s;
        cin>>s;
        int m=0;
        for (auto i:s){
            m|=(1ll<<(i-'a'));
        }
        mask[i]=m;
        vec.pb(m);
    }

    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());

    vi ans(len(vec),0);

    for (int i=0;i<len(s);i++){
        last[s[i]]=i;
        vector<pii> v(0);
        for (int j='a';j<='z';j++){
            if (last[j]!=-1){
                v.pb({last[j],j});
            }
        }
        sort(all(v));
        int m=0;
        for (int j=len(v)-1;j>=0;j--){
            m|=(1ll<<(v[j].sec-'a'));
            if (i==len(s)-1||!(m&(1ll<<(s[i+1]-'a')))){
                auto it=lower_bound(all(vec),m);
                if (it!=vec.end()&&*it==m){
                    ans[it-vec.begin()]++;
                }
            }
        }
    }

    for (int i=0;i<q;i++){
        cout<<ans[lower_bound(all(vec),mask[i])-vec.begin()]<<"\n";
    }
}