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

vi vec[arr];
//vi pref[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int p,c;
        cin>>p>>c;
        vec[p].pb(c);
    }
    for (int i=1;i<=m;i++){
        sort(all(vec[i]),greater<int>());
//        for (int j=0;j<len(vec[i]);j++){
//            if (j){
//                pref[i].pb(pref[i].back()+vec[i][j]);
//            }
//            else{
//                pref[i].pb(vec[i][j]);
//            }
//        }
    }
    int ans=1e18;
    for (int i=max(len(vec[1]),1ll);i<=n;i++){
        vi vec1;
        vi vec2;
        for (int j=2;j<=m;j++){
            for (int k=0;k<min(len(vec[j]),i-1);k++){
                vec2.pb(vec[j][k]);
            }
            for (int k=i-1;k<len(vec[j]);k++){
                vec1.pb(vec[j][k]);
            }
        }
        sort(all(vec1),greater<int>());
        sort(all(vec2),greater<int>());
        int cur_ans=0;
        int cur_size=len(vec[1]);
        for (auto i:vec1){
            cur_ans+=i;
            cur_size++;
        }
//        cout<<i<<" "<<cur_ans<<" "<<cur_size<<"\n";
        while (cur_size<i){
            cur_ans+=vec2.back();
            vec2.pop_back();
            cur_size++;
        }
//        cout<<i<<" "<<cur_ans<<" "<<cur_size<<"\n";
        ans=min(ans,cur_ans);
    }
    cout<<ans<<"\n";
}