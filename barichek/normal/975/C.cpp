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

int a[arr];
int pref[arr];

int get(int l,int r)
{
    if (l>r){
        return 0;
    }
    return pref[r]-pref[l-1];
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    int pos=1;
    int cur=a[1];
    for (int i=1;i<=q;i++){
        int k;
        cin>>k;
        if (k>=cur+get(pos+1,n)){
            pos=1;
            cur=a[1];
        }
        elif (k<cur){
            cur-=k;
        }
        else{
            int l=pos,r=n;
            while (r-l>0){
                int m=(l+r+1)/2;
                if (k>=cur+get(pos+1,m)){
                    l=m;
                }
                else{
                    r=m-1;
                }
            }
            /// all in [pos;l]
            k-=cur+get(pos+1,l);
            pos=l+1;
            cur=a[pos]-k;
        }
        cout<<n-pos+1<<"\n";
    }
}