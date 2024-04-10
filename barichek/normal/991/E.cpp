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

int cnt[arr];

map<vector<int>,int> dp;
vector<vector<int>> vectors;

void build(int pos,vector<int> cur)
{
    if (pos==10){
        vectors.pb(cur);
        return;
    }
    cur.pb(-1);
    for (int j=0;j<=cnt[pos];j++){
        cur.back()=j;
        build(pos+1,cur);
    }
}

int sum(vector<int> a)
{
    int res=0;
    for (auto i:a){
        res+=i;
    }
    return res;
}

bool cmp(vector<int> a,vector<int> b)
{
    return sum(a)<sum(b);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (auto i:s){
        cnt[i-'0']++;
    }
    build(0,{});
    dp[{0,0,0,0,0,0,0,0,0,0}]=1;
    sort(all(vectors),cmp);
    for (auto i:vectors){
        vi new_i=i;
        for (int j=0;j<10;j++){
            if (i[j]!=cnt[j]&&(j!=0||sum(i)!=0)){
                new_i[j]++;
                dp[new_i]+=dp[i];
                new_i[j]--;
            }
        }
    }
    int ans=0;
    for (auto i:vectors){
        bool ok=1;
        for (int j=0;j<10;j++){
            if (cnt[j]!=0&&i[j]==0){
                ok=0;
            }
        }
        if (ok){
            ans+=dp[i];
        }
    }
    cout<<ans<<"\n";
}