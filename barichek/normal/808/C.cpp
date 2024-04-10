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

int a[arr];
int ans[arr];
int n,w;

bool is_good()
{
    for (int i=1;i<=n;i++){
        if (ans[i]<(a[i]+1)/2){
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i]>a[i]){
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i!=j){
                if (ans[i]<ans[j]){
                    if (a[i]>a[j]){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int pos_to_push()
{
    for (int i=1;i<=n;i++){
        if (ans[i]<(a[i]+1)/2){
            return i;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i!=j){
                if (ans[i]<ans[j]){
                    if (a[i]>a[j]){
                        return i;
                    }
                }
            }
        }
    }
    int pos=1;
    for (int i=2;i<=n;i++){
        if (ans[i]<a[i]){
            if (a[i]>a[pos]||(pos==1&&ans[1]>=a[1])){
                pos=i;
            }
        }
    }
    return pos;
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

    cin>>n>>w;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    while (w){
        //cout<<"pos :: "<<pos_to_push()<<"\n";
        ans[pos_to_push()]++;
        w--;
    }
    if (!is_good()||w!=0){
        return cout<<-1<<"\n", 0;
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}