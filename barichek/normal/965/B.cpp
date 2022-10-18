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
///#define int long long

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

char a[ar][ar];
int cnt[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j+k-1<n;j++){
            bool ok=1;
            for (int l=j;l<j+k;l++){
                ok&=(a[i][l]=='.');
            }
            if (ok){
                for (int l=j;l<j+k;l++){
                    cnt[i][l]++;
                }
            }
        }
    }
    for (int i=0;i+k-1<n;i++){
        for (int j=0;j<n;j++){
            bool ok=1;
            for (int l=i;l<i+k;l++){
                ok&=(a[l][j]=='.');
            }
            if (ok){
                for (int l=i;l<i+k;l++){
                    cnt[l][j]++;
                }
            }
        }
    }
    vector<pair<int,pii>> v(0);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
//            cout<<"cnt["<<i<<"]["<<j<<"] :: "<<cnt[i][j]<<"\n";
            if (a[i][j]=='.'){
                v.pb({cnt[i][j],{i,j}});
            }
        }
    }
    sort(all(v));
    reverse(all(v));
    if (v.empty()){
        cout<<1<<" "<<1<<"\n";
    }
    else{
        cout<<v.front().sec.fir+1<<" "<<v.front().sec.sec+1<<"\n";
    }
}