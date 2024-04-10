//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18+10;
 
///---program start---///

int ask(int u,int v)
{
    fflush(stdout);
    cout<<"?"<<" "<<u<<" "<<v<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    fflush(stdout);
    return res;
}

vi reb[arr];

int a[arr];

bool active[arr];

void dfs(int now,int pred)
{
    active[now]=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
        }
    }
}

int cnt_near_active[arr];

void answer(int a)
{
    fflush(stdout);
    cout<<"!"<<" "<<a<<"\n";
    fflush(stdout);
    exit(0);
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        active[i]=1;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    while (true){
        for (int i=1;i<=n;i++){
            cnt_near_active[i]=0;
        }
        for (int i=1;i<=n;i++){
            for (int j:reb[i]){
                if (active[j]){
                    cnt_near_active[i]++;
                }
            }
        }
        int x2=-1,x3=-1;
        for (int i=1;i<=n;i++){
            for (int j:reb[i]){
                if (cnt_near_active[i]!=1&&active[i]&&active[j]&&cnt_near_active[j]!=1){
                    x2=i;
                    x3=j;
                    break;
                }
            }
        }
        if (x2==-1){
            break;
        }
        else{
            int res=ask(x2,x3);
            if (res==x2){
                dfs(x3,x2);
            }
            else{
                dfs(x2,x3);
            }
        }
    }
    
        for (int i=1;i<=n;i++){
            cnt_near_active[i]=0;
        }
        for (int i=1;i<=n;i++){
            for (int j:reb[i]){
                if (active[j]){
                    cnt_near_active[i]++;
                }
            }
        }
        
    int best=-1;
    for (int i=1;i<=n;i++){
        if (active[i]&&(best==-1||cnt_near_active[i]>cnt_near_active[best])){
            best=i;
        }
    }
    if (cnt_near_active[best]==0){
        answer(best);
    }
    vi guys(0);
    for (int i=1;i<=n;i++){
        if (i!=best&&active[i]){
            guys.pb(i);
        }
    }
    if (len(guys)%2==1){
        int L=guys.back();
        guys.pop_back();
        for (int i=0;i<len(guys);i+=2){
            int u=guys[i];
            int v=guys[i+1];
            int res=ask(u,v);
            if (res==u||res==v){
                answer(res);
            }
        }
        answer(ask(L,best));
    }
    else{
        for (int i=0;i<len(guys);i+=2){
            int u=guys[i];
            int v=guys[i+1];
            int res=ask(u,v);
            if (res==u||res==v){
                answer(res);
            }
        }
        answer(best);
    }
}