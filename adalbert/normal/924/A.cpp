#pragma GCC optimize("O3")
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

vi reb[arr];
char a[ar][ar];
int cur=0;
int cnt1=0;
int cnt2=0;
bool use[arr];

void dfs(int now)
{
    use[now]=1;
    if (now<=60){
        cnt1++;
    }
    else{
        cnt2++;
    }
    if (now<=60){
        cur+=len(reb[now]);
    }
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs(wh);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            if (a[i][j]=='#'){
                reb[i].pb(j+100);
                reb[j+100].pb(i);
            }
        }
    }

    for (int i=1;i<=n;i++){
        if (!use[i]){
            cur=0;
            cnt1=0;
            cnt2=0;
            dfs(i);
            if (cur!=cnt1*cnt2){
                cout<<"No"<<"\n";
                return 0;
            }
        }
    }
    cout<<"Yes"<<"\n";
}