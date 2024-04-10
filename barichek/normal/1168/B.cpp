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

const int N=3e5+10;
//const int N=10;
int best[N];
#define left left_____
#define right right_____
bitset<N> left;
bitset<N> right;
bitset<N> rright;
bitset<N> res;
bitset<N> all;
int ans[N];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<N;i++){
        all[i]=1;
    }

    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        right[i]=bool(s[i]-'0');
        rright[i]=bool(s[i]-'0')^1;
    }
    for (int i=0;i<len(s);i++){
//        cout<<i<<" "<<left<<" "<<right<<"\n";
        res=((right^left^all))&(s[i]=='0'?rright:right);
//        res>>=1;
        int kek=res._Find_next(0);
//        kek++;
        if (i-kek>=0&&i+kek<len(s)){
            best[i]=kek;
        }
        else{
            best[i]=0;
        }
//        cout<<i<<" "<<kek<<"\n";
        right>>=1;
        rright>>=1;
        left[0]=bool(s[i]-'0');
        left<<=1;
    }
    int n=len(s);
    for (int i=0;i<n;i++){
        ans[i]=-1;
    }
    for (int i=0;i<n;i++){
        if (best[i]){
            ans[i+best[i]]=max(ans[i+best[i]],i-best[i]);
        }
    }
    for (int i=1;i<n;i++){
        ans[i]=max(ans[i],ans[i-1]);
    }
    ll answer=0;
    for (int i=0;i<n;i++){
        answer+=ans[i]+1;
    }
    cout<<answer<<"\n";
}