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

int close[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    vector<pii> a(n-1);
    for (auto& i:a){
        cin>>i.fir>>i.sec;
    }
    for (auto i:a){
        if (i.sec!=n){
            cout<<"NO"<<"\n";
            return 0;
        }
        close[i.fir]++;
    }
    vector<pii> ans(0);
    vi open(0);
    for (int i=1;i<n;i++){
        if (!close[i]){
            open.pb(i);
        }
    }
    for (int i=n-1;i>=1;i--){
        if (!close[i]){
            continue;
        }
        vi cur(0);
        cur.pb(n);
        while (close[i]>1){
            if (open.empty()){
                cout<<"NO"<<"\n";
                return 0;
            }

            if (open.back()>i){
                cout<<"NO"<<"\n";
                return 0;
            }

            cur.pb(open.back());
            open.pop_back();
            close[i]--;
        }
        cur.pb(i);
        for (int i=1;i<len(cur);i++){
            ans.pb({cur[i-1],cur[i]});
        }
    }
    if (!open.empty()){
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
    cout<<"\n";
}