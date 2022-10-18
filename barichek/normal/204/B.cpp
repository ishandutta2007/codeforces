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

map<int,int> cnt1;
map<int,int> cnt2_not_equal_1;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    set<int> kek;
    kek.clear();
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cnt1[a]++;
        if (a!=b){
            cnt2_not_equal_1[b]++;
        }
        kek.insert(a);
        kek.insert(b);
    }
    int ans=1e18;
    for (auto i:kek){
        int want=(n+1)/2;
        int cur_ans=0;
        int have=cnt1[i];
        if (have<want){
            int lol=min(want-have,cnt2_not_equal_1[i]);
            have+=lol;
            cur_ans+=lol;
        }
        if (have>=want){
            ans=min(ans,cur_ans);
        }
    }
    cout<<(ans>1e9?-1:ans)<<"\n";
}