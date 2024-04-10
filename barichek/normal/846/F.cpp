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

#define arr (int)(1e6+10)

int a[arr];
int had[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
//    int ans=0;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            int l=i,r=j;
//            if (l>r){
//                swap(l,r);
//            }
//            set<int> s;
//            s.clear();
//            for (int k=l;k<=r;k++){
//                s.insert(a[k]);
//            }
//            ans+=len(s);
//        }
//    }
//    cout<<"ans :: "<<ans<<"\n";
//    cout<<fixed<<setprecision(10)<<(ld)(ans)/ld(n*n)<<"\n";
    int ans=0;
    int cur=0;
    for (int i=1;i<=n;i++){
//        cout<<"a[i] :: "<<a[i]<<"\n";
        if (!had[a[i]]){
            had[a[i]]=i;
            cur+=i;
        }
        else{
            cur+=i;
            cur-=had[a[i]];
//            cout<<"kek1 :: "<<had[a[i]]<<"\n";
//            cout<<"cur+="<<i<<"\n";
//            cout<<"cur-="<<had[a[i]]<<"\n";
            had[a[i]]=i;
        }
        ans+=2*(cur-1)+1;
//        cout<<"i :: "<<i<<" :: ans+="<<2*(cur-1)+1<<"\n";
//        cout<<"i :: "<<i<<" && cur :: "<<cur<<"\n";
    }
//    cout<<"ans :: "<<ans<<"\n";
    cout<<fixed<<setprecision(10)<<(ld)(ans)/ld(n*n)<<"\n";
}