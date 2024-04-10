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

#define oryshych_jebosh main

///---program start---///

int n,m,s;
vector<pii> a;
vector<pair<pii,int>> b;
int ans[arr];

bool check(int x)
{
    vi cnt(n,x);
    set<pii> q;
    q.clear();
    int p=n-1;
    int lol=0;
    for (int i=len(a)-1;i>=0;i--){
        while (p>=0&&b[p].fir.fir>=a[i].fir){
            q.insert(mp(b[p].fir.sec,p));
            p--;
        }
        if (q.empty()){
            return 0;
        }
        auto now=*q.begin();
        q.erase(q.begin());
        lol+=now.fir;
        cnt[now.sec]--;
        if (cnt[now.sec]){
            q.insert(mp(0,now.sec));
        }
        ans[a[i].sec]=b[now.sec].sec;
    }
    return lol<=s;
}

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    cin>>n>>m>>s;
    a.resize(m);
    for (int i=0;i<m;i++){
        cin>>a[i].fir;
        a[i].sec=i;
    }
    b.resize(n);
    for (int i=0;i<n;i++){
        cin>>b[i].fir.fir;
    }
    for (int i=0;i<n;i++){
        cin>>b[i].fir.sec;
    }
    for (int i=0;i<n;i++){
        b[i].sec=i;
    }

    sort(all(a));
    sort(all(b));
    if (!check(1e5)){
        return cout<<"NO"<<"\n", 0;
    }
    int l=1,r=1e5;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    check(l);
    cout<<"YES"<<"\n";
    for (int i=0;i<m;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
}