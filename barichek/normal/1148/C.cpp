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

#define arr (int)(3e5+10)

int p[arr];
int pos_of[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>p[i];
        pos_of[p[i]]=i;
    }
    if (n==1){
        if (p[1]==1){
            cout<<0<<"\n";
        }
        else{
            cout<<1<<"\n";
            cout<<1<<" "<<2<<"\n";
        }
        return 0;
    }
    vector<pii> ans(0);
    auto sw=[&](int a,int b)
    {
        if (a==b){
            return 0;
        }
        ans.pb(mp(a,b));
        assert(abs(a-b)>=n/2);
        pos_of[p[a]]=b;
        pos_of[p[b]]=a;
        swap(p[a],p[b]);
    };
    for (int i=n;i>=n/2+1;i--){
        if (p[i]!=i){
            if (abs(i-pos_of[i])>=n/2){
                sw(i,pos_of[i]);
            }
            else{
                int pp=pos_of[i];
                if (pp<=n/2){
                    sw(pp,n);
                    sw(1,n);
                    sw(1,i);
                }
                else{
                    sw(1,pp);
                    sw(1,i);
                }
            }
        }
    }
    for (int i=n/2;i>=1;i--){
        if (p[i]!=i){
            int pp=pos_of[i];
            sw(pp,n);
            sw(i,n);
            sw(pp,n);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
    for (int i=1;i<=n;i++){
        assert(p[i]==i);
    }
}