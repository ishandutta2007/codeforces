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

int cnt_____[2000];
int* cnt=cnt_____+1000;

bool check(int n,int y,int k)
{
    memset(cnt_____,0,sizeof(cnt_____));
    int kek=0;
    for (int i=0;i<=62;i++){
        if (n&(1ll<<i)){
            cnt[i]++;
            kek++;
        }
    }
    for (int i=62;i>y&&kek<=k;i--){
        while (cnt[i]&&kek<=k){
            cnt[i]-=1;
            cnt[i-1]+=2;
            kek++;
        }
    }
    return kek<=k;
}

void build(int n,int y,int k)
{
    memset(cnt_____,0,sizeof(cnt_____));
    int kek=0;
    for (int i=0;i<=62;i++){
        if (n&(1ll<<i)){
            cnt[i]++;
            kek++;
        }
    }
    for (int i=62;i>y;i--){
        while (cnt[i]){
            cnt[i]-=1;
            cnt[i-1]+=2;
            kek++;
        }
    }
    multiset<int> s;
    s.clear();
    for (int i=-70;i<=70;i++){
        while (cnt[i]--){
            s.insert(i);
        }
    }
    while (len(s)<k){
        int val=*s.begin();
        s.erase(s.begin());
        s.insert(val-1);
        s.insert(val-1);
    }
    while (!s.empty()){
        cout<<*(--s.end())<<" ";
        s.erase((--s.end()));
    }
    cout<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    if (k<__builtin_popcountll(n)){
        return cout<<"No"<<"\n", 0;
    }
    for (int i=-70;i<=70;i++){
        if (check(n,i,k)){
            cout<<"Yes"<<"\n";
            build(n,i,k);
            return 0;
        }
    }
    assert(0);
}