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

#define oryshych_jebosh main

///---program start---///

int cnt_in[arr];
int cnt_out[arr];
int ans[arr];
vi cnt_in_vh[arr];
vi cnt_out_vh[arr];

int type[arr];
int a[arr];

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    int cnt1=0;
    for (int i=1;i<=n;i++){
        char c;
        cin>>c;
        cin>>a[i];
        type[i]=(c=='+');
        if (type[i]){
            cnt_in[a[i]]++;
            cnt_in_vh[a[i]].pb(i);
        }
        else{
            cnt_out[a[i]]++;
            cnt_out_vh[a[i]].pb(i);
            cnt1++;
        }
    }
//    cout<<"at start ans :: "<<"\n";
//    for (int i=1;i<=n;i++){
//        cout<<ans[i]<<" ";
//    }
//    cout<<"\n";
    int kek1=0;
    for (int i=1;i<=n;i++){
        int cur_ok=0;
        cur_ok+=cnt_in[i];
//        cout<<"cnt_in["<<i<<"] :: "<<cnt_in[i]<<"\n";
//        cout<<"cnt1-cnt_in["<<i<<"] :: "<<cnt1<<"-"<<cnt_out[i]<<"\n";
        cur_ok+=cnt1-cnt_out[i];
        if (cur_ok==m){
//            cout<<"can be murder :: "<<i<<" !!!!!\n";
            kek1++;
            for (auto j:cnt_in_vh[i]){
                ans[j]++;
            }
            for (auto j:cnt_out_vh[i]){
                ans[j]--;
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (!type[i]){
            ans[i]+=kek1;
        }
    }
//    cout<<"at end ans :: "<<"\n";
//    for (int i=1;i<=n;i++){
//        cout<<ans[i]<<" ";
//    }
//    cout<<"\n";
    for (int i=1;i<=n;i++){
        if (ans[i]==kek1){
            cout<<"Truth"<<"\n";
        }
        elif (ans[i]==0){
            cout<<"Lie"<<"\n";
        }
        else{
            cout<<"Not defined"<<"\n";
        }
    }
}