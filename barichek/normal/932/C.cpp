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

#define arr (int)(1e6+10)

int dp[arr];
int pred[arr];
int ans[arr];

void build_kek(int l,int r)
{
    for (int i=l;i<r;i++){
        ans[i]=i+1;
    }
    ans[r]=l;
}

void build_answer(vi res)
{
    int cur=1;
    for (auto i:res){
        build_kek(cur,cur+i-1);
        cur+=i;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,a,b;
    cin>>n>>a>>b;
    dp[0]=1;
    for (int i=0;i<arr;i++){
        if (dp[i]){
            if (i+a<arr){
                if (!dp[i+a]){
                    dp[i+a]=1;
                    pred[i+a]=a;
                }
            }
            if (i+b<arr){
                if (!dp[i+b]){
                    dp[i+b]=1;
                    pred[i+b]=b;
                }
            }
        }
    }
    if (!dp[n]){
        return cout<<-1<<"\n", 0;
    }
    vi res(0);
    int cur=n;
    while (cur){
        res.pb(pred[cur]);
        cur-=pred[cur];
    }
    build_answer(res);
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}