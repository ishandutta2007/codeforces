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

///---program start---///

int a[arr];
int first[arr];
int last[arr];
int cnt[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        if (first[a[i]]==0){
            first[a[i]]=i;
        }
        last[a[i]]=i;

        cnt[a[i]]++;
    }
    vector<int> vec;
    for (int i=0;i<arr;i++){
        if (first[i]){
            vec.pb(i);
        }
    }
    sort(all(vec),[&](int a,int b){
        return first[a]<first[b];
    });
    int ans=n;
    for (int i=0;i<len(vec);){
        int j=i+1;
        int cur=last[vec[i]];
        while (j<len(vec)&&first[vec[j]]<cur){
            cur=max(cur,last[vec[j]]);
            j++;
        }
        int m=0;
        for (int k=i;k<j;k++){
            m=max(m,cnt[vec[k]]);
        }
        ans-=m;
        i=j;
    }
    cout<<ans<<"\n";
}