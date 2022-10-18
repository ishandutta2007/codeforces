#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

vi a[arr];

vi kek(vi a,vi b)
{
    vi res=b;
    for (int i=0;i<5;i++){
        res[i]-=a[i];
    }
    return res;
}

ld mult(vi a,vi b)
{
    ld res=0;
    for (int i=0;i<5;i++){
        res+=a[i]*b[i];
    }
    return res;
}

ld angle(vi a,vi b,vi c)
{
    ld res=0;
    res=mult(kek(b,a),kek(c,a));
    res/=sqrtl(mult(kek(b,a),kek(b,a)));
    res/=sqrtl(mult(kek(c,a),kek(c,a)));
    return acos(res);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n;
    cin>>n;
    if (n>100){
        return cout<<0<<"\n", 0;
    }
    for (int i=0;i<n;i++){
        a[i].resize(5);
        for (auto& j:a[i]){
            cin>>j;
        }
    }
    vi ans(0);
    for (int i=0;i<n;i++){
        bool ok=1;
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                cerr<<i<<" "<<j<<" "<<k<<"\n";
                if (i!=j&&i!=k&&j!=k){
                    ld cur=angle(a[i],a[j],a[k]);
                    if (cur>=0&&cur<pi/2.0){
                        ok=0;
                    }
                }
            }
        }
        if (ok){
            ans.pb(i+1);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}