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

int n,m;
int lol[arr];
int a[arr];
int b[arr];
int kek[arr];

int dist(int a,int b)
{
    if (a<=b){
        return b-a;
    }
    else{
        return n-a+b;
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            lol[j]=0;
            kek[j]=1e9;
        }
        for (int j=0;j<m;j++){
            lol[a[j]]++;
            kek[a[j]]=min(kek[a[j]],dist(a[j],b[j]));
        }
        int ans=0;
        for (int j=1;j<=n;j++){
            if (!lol[j]){
                continue;
            }
            int cur_ans=dist(i,j)+n*(lol[j]-1)+kek[j];
            ans=max(ans,cur_ans);
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}