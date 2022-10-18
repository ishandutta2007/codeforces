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
    #else
        files("");
        files_ds("");
    #endif

    /// a rechi hvorii
    /// i ti, vshe tut u tomy holi
    /// idy na golos miy
    /// idy na golos miy

    /// hay navit ne zbudetsya
    /// zavtra nehayno i nevidvorotnyo vidbudetsya

    int n,k;
    cin>>n>>k;
    vi a(k);
    int cnt2=2*n;
    int cnt4=n;
    int cnt1=0;
    for (auto& i:a){
        cin>>i;
    }
    sort(all(a),greater<int>());
    for (auto i:a){
        int cur=i;
        while (cur>0){
            if (cnt4){
                cnt4--;
                if (cur==1){
                    cnt2++;
                }
                elif (cur==2){
                    cnt1++;
                }
                cur-=4;
            }
            elif (cnt2){
                cnt2--;
                cur-=2;
            }
            elif (cnt1){
                cnt1--;
                cur--;
            }
            else{
                return cout<<"NO"<<"\n", 0;
            }
        }
    }
    cout<<"YES"<<"\n";
}