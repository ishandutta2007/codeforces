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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int p,k;
    cin>>p>>k;
    vi ans(0);
    while (p){
        ans.pb(p%k);
        p/=k;
    }
    for (int i=1;i<len(ans);i+=2){
        ans[i]*=-1;
    }
    for (int i=1;i<len(ans);i++){
        if (ans[i]<0){
            ans[i]=k+ans[i];
            if (i==len(ans)-1){
                ans.pb(1);
            }
            else{
                ans[i+1]++;
            }
        }
        elif (ans[i]==k){
            ans[i]=0;
            if (i==len(ans)-1){
                ans.pb(-1);
            }
            else{
                ans[i+1]--;
            }
        }
    }

    int kek=0;
    int cur=1;
    for (auto i:ans){
        kek+=cur*i;
        cur=cur*(-k);
    }
//    cout<<kek<<"\n";

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}