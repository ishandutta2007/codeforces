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

int n;
int c[arr];
vi vec[arr];
vi rvec[arr];

int st[arr];

set<int> open[arr];

int solve(int x)
{
    for (int i=1;i<=n;i++){
        st[i]=0;
    }
    for (int i=1;i<=n;i++){
        st[i]=len(vec[i]);
    }
    for (int i=1;i<=3;i++){
        open[i].clear();
    }
    for (int i=1;i<=n;i++){
        if (st[i]==0){
            open[c[i]].insert(i);
        }
    }
    int cur=x;
    int ans=0;
    int cnt_del=0;
    while (cnt_del!=n){
        while (open[cur].empty()){
            cur=(cur==3?1:cur+1);
            ans++;
        }
        while (!open[cur].empty()){
            int now=*open[cur].begin();
            open[cur].erase(open[cur].begin());
            cnt_del++;
            for (auto wh:rvec[now]){
                st[wh]--;
                if (st[wh]==0){
                    open[c[wh]].insert(wh);
                }
            }
        }
    }
    return ans+n;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        int s;
        cin>>s;
        vec[i].resize(s);
        for (auto& j:vec[i]){
            cin>>j;
            rvec[j].pb(i);
        }
    }
    int ans=1e18;
    ans=min(ans,solve(1));
    ans=min(ans,solve(2));
    ans=min(ans,solve(3));
    cout<<ans<<"\n";
}