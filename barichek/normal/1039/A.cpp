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

int a[arr];
int b[arr];
int x[arr];

int cant[arr];
int lol[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,t;
    cin>>n>>t;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]+t;
    }
    for (int i=1;i<=n;i++){
        cin>>x[i];
        if (x[i]<i){
            cout<<"No"<<"\n";
            return 0;
        }

        lol[i+1]++;
        lol[x[i]+1]--;

        b[x[i]]=max(b[x[i]],a[i]+t);
    }
    for (int i=1;i<=n;i++){
        lol[i]+=lol[i-1];
        if (lol[i]!=0){
            b[i-1]=max(b[i-1],a[i]+t);
        }
    }
    for (int i=2;i<=n;i++){
        b[i]=max(b[i],b[i-1]+1);
    }
    for (int i=2;i<=n;i++){
        cant[i]=(b[i-1]<a[i]+t);
//        cout<<"cant["<<i<<"] :: "<<cant[i]<<"\n";
    }
    for (int i=2;i<=n;i++){
        cant[i]+=cant[i-1];
    }
//    for (int i=1;i<=n;i++){
//        cout<<b[i]<<" ";
//    }
//    cout<<"\n";
    for (int i=1;i<=n;i++){
        if (x[i]!=n){
            int cur=cant[x[i]+1]-cant[i];
            if (cur==0){
                cout<<"No"<<"\n";
                return 0;
            }
        }
    }
    cout<<"Yes"<<"\n";
    for (int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}