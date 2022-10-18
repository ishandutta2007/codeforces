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

multiset<int> b[arr];
int bor[arr][26];
int cnt=1;

void add(string s)
{
    int deep=0;
    int cur=1;
    for (auto i:s){
        deep++;
        if (!bor[cur][i-'a']){
            bor[cur][i-'a']=++cnt;
        }
        cur=bor[cur][i-'a'];
    }
    b[cur].insert(deep);
}

void dfs(int now,int deep=0)
{
    bool can=(b[now].empty()&&deep!=0);
    for (int i=0;i<26;i++){
        if (bor[now][i]){
            int to=bor[now][i];
            dfs(to,deep+1);
            if (len(b[to])>len(b[now])){
                b[now].swap(b[to]);
            }
            for (auto i:b[to]){
                b[now].insert(i);
            }
        }
    }
    if (can&&!b[now].empty()){
        b[now].erase((--b[now].end()));
        b[now].insert(deep);
    }
//    cout<<"vertex :: "<<now<<" ::: ";
//    for (auto i:b[now]){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        add(s);
    }
    dfs(1);
    int ans=0;
    for (auto i:b[1]){
        ans+=i;
    }
    cout<<ans<<"\n";
}