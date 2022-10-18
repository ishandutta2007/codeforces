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
int b[arr];
vi vh[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    string t;
    cin>>s>>t;

    for (int i=0;i<len(t);i++){
        vh[t[i]].pb(i);
    }

    int p;

    p=0;
    for (int i=0;i<len(t);i++){
        while (p<len(s)){
            if (s[p]==t[i]){
                a[p]=i;
                p++;
                break;
            }
            else{
                a[p]=i-1;
            }
            p++;
        }
    }
    while (p<len(s)){
        a[p]=(p==0?0:a[p-1]);
        p++;
    }

    p=len(s)-1;
    for (int i=len(t)-1;i>=0;i--){
        while (p>=0){
            if (s[p]==t[i]){
                b[p]=i;
                p--;
                break;
            }
            else{
                b[p]=i+1;
            }
            p--;
        }
    }
    while (p>=0){
        b[p]=(p==len(s)-1?0:b[p+1]);
        p--;
    }

    for (int i=0;i<len(s);i++){
        int k1=(i==0?-1:a[i-1]);
        int k2=(i==len(s)-1?len(t):b[i+1]);
        k2--;
        k1++;
        /// j in [k2;k1]
        bool ok=0;
        if (k2<=k1){
            auto it=lower_bound(all(vh[s[i]]),k2);
            if (it!=vh[s[i]].end()&&*it<=k1){
                ok=1;
            }
        }
        if (!ok){
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
}