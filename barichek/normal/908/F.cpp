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

#define arr (int)(1e6+10)

bool use[arr];
bool interesting[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    vector<pii> a(0);
    /**
        1 - 1
        2 - 2
        3 - both
    */

    bool any_3=0;
    while (n--){
        int x;
        cin>>x;
        char type;
        cin>>type;
        if (type=='R'){
            a.pb({x,1});
        }
        elif (type=='B'){
            a.pb({x,2});
        }
        else{
            any_3=1;
            a.pb({x,3});
        }
    }
    sort(all(a));
    if (!any_3){
        vi all_1(0);
        vi all_2(0);
        for (auto i:a){
            if (i.sec==1){
                all_1.pb(i.fir);
            }
            else{
                all_2.pb(i.fir);
            }
        }
        int ans=0;
        if (!all_1.empty()){
            ans+=all_1.back()-all_1.front();
        }
        if (!all_2.empty()){
            ans+=all_2.back()-all_2.front();
        }
        return cout<<ans<<"\n", 0;
    }
    int ans=0;
    for (int i=0;i<len(a);i++){
        if (a[i].sec==3){
            use[i]=1;
        }
    }
    memset(interesting,1,sizeof(interesting));
    /// from front
    int kek1;
    int kek2;
    kek1=-1e18;
    kek2=-1e18;
    for (int i=0;i<len(a);i++){
        if (a[i].sec==3){
            if (kek1!=-1e18){
                ans+=a[i].fir-kek1;
            }
            if (kek2!=-1e18){
                ans+=a[i].fir-kek2;
            }
            break;
        }
        if (kek1==-1e18&&a[i].sec==1){
            kek1=a[i].fir;
        }
        if (kek2==-1e18&&a[i].sec==2){
            kek2=a[i].fir;
        }
        interesting[i]=0;
    }
    /// from back
    kek1=+1e18;
    kek2=+1e18;
    for (int i=len(a)-1;i>=0;i--){
        if (a[i].sec==3){
            if (kek1!=+1e18){
                ans-=a[i].fir-kek1;
            }
            if (kek2!=+1e18){
                ans-=a[i].fir-kek2;
            }
            break;
        }
        if (kek1==+1e18&&a[i].sec==1){
            kek1=a[i].fir;
        }
        if (kek2==+1e18&&a[i].sec==2){
            kek2=a[i].fir;
        }
        interesting[i]=0;
    }
    int last=-1;
    for (int i=0;i<len(a);i++){
        if (interesting[i]){
            if (use[i]){
                if (i!=0&&use[i-1]&&interesting[i-1]){
                    ans+=a[i].fir-a[i-1].fir;
                }
                elif (i!=0&&interesting[i-1]){
                    vi all_1(0);
                    vi all_2(0);
                    for (int j=last+1;j<i;j++){
                        if (a[j].sec==1){
                            all_1.pb(a[j].fir);
                        }
                        else{
                            all_2.pb(a[j].fir);
                        }
                    }

                    if (all_1.empty()||all_2.empty()){
                        if (all_1.empty()){
                            all_1=all_2;
                        }
                        int max_diff=0;
                        max_diff=max(max_diff,all_1.front()-a[last].fir);
                        all_1.pb(a[i].fir);
                        for (int j=1;j<len(all_1);j++){
                            max_diff=max(max_diff,all_1[j]-all_1[j-1]);
                        }
                        ans+=2*(a[i].fir-a[last].fir)-max_diff;
                    }
                    else{
                        int cur1=2*(a[i].fir-a[last].fir);
                        int cur2=a[i].fir-a[last].fir;
                        if (1){
                            int max_diff=0;
                            max_diff=max(max_diff,all_1.front()-a[last].fir);
                            all_1.pb(a[i].fir);
                            for (int j=1;j<len(all_1);j++){
                                max_diff=max(max_diff,all_1[j]-all_1[j-1]);
                            }
                            cur2+=a[i].fir-a[last].fir-max_diff;
                        }
                        if (1){
                            int max_diff=0;
                            max_diff=max(max_diff,all_2.front()-a[last].fir);
                            all_2.pb(a[i].fir);
                            for (int j=1;j<len(all_2);j++){
                                max_diff=max(max_diff,all_2[j]-all_2[j-1]);
                            }
                            cur2+=a[i].fir-a[last].fir-max_diff;
                        }
                        ans+=min(cur1,cur2);
//                        /// if took all 1
//                        int cur1=0;
//                        if (!all_2.empty()){
//                            int max_diff=0;
//                            max_diff=max(max_diff,all_2.front()-a[last].fir);
//                            all_2.pb(a[i].fir);
//                            for (int j=1;j<len(all_2);j++){
//                                max_diff=max(max_diff,all_2[j]-all_2[j-1]);
//                            }
////                            cout<<"max_diff1 :: "<<max_diff<<"\n";
////                            cout<<"before :: "<<cur1<<"\n";
//                            cur1+=a[i].fir-a[last].fir-max_diff;
//                        }
//                        else{
//                            cur1+=a[i].fir-a[last].fir;
//                        }
//
//                        /// if took all 2
//                        int cur2=0;
//                        if (!all_1.empty()){
//                            int max_diff=0;
//                            max_diff=max(max_diff,all_1.front()-a[last].fir);
//                            all_1.pb(a[i].fir);
//                            for (int j=1;j<len(all_1);j++){
//                                max_diff=max(max_diff,all_1[j]-all_1[j-1]);
//                            }
////                            cout<<"max_diff2 :: "<<max_diff<<"\n";
////                            cout<<"before :: "<<cur2<<"\n";
//                            cur2+=a[i].fir-a[last].fir-max_diff;
//                        }
//                        else{
//                            cur2+=a[i].fir-a[last].fir;
//                        }
//
////                        cout<<"curs :: "<<cur1<<" "<<cur2<<"\n";
//
//                        ans+=cur1+cur2;
                    }
                }
                last=i;
            }
        }
    }

    cout<<ans<<"\n";
}