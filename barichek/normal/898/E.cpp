#pragma GCC optimize("O3")
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

bool is_kek(int a)
{
    for (int i=sqrtl(a)-2;i<=sqrtl(a)+2;i++){
        if (i*i==a){
            return 1;
        }
    }
    return 0;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    vi kek1(0);
    vi kek2(0);
    while (n--){
        int a;
        cin>>a;
        if (is_kek(a)){
            kek1.pb(a); /// squares
        }
        else{
            kek2.pb(a); /// not squares
        }
    }
    if (len(kek1)>=len(kek2)){
        /// to do
        vi costs(0);
        for (auto i:kek1){
            if (i==0){
                costs.pb(2);
            }
            else{
                costs.pb(1);
            }
        }
        sort(all(costs));
        int ans=0;
        for (int i=0;i<(len(kek1)-len(kek2))/2;i++){
            ans+=costs[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    vi keks(0);
    for (int i=0;i*i<=2e9;i++){
        keks.pb(i*i);
    }
    vi costs(0);
    for (auto i:kek2){
        int cur=0;
        auto it1=upper_bound(all(keks),i);
        auto it2=upper_bound(all(keks),i);
        it2--;
        costs.pb(min(abs(i-*it1),abs(i-*it2)));
    }
    sort(all(costs));
    int ans=0;
    for (int i=0;i<(len(kek2)-len(kek1))/2;i++){
        ans+=costs[i];
    }
    cout<<ans<<"\n";
}