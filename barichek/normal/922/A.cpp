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

    int x,y;
    cin>>x>>y;
    swap(x,y);
    if (y==0){
        if (x==1){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }
    else{
        if (x<2){
            cout<<"No"<<"\n";
            return 0;
        }
        int kek=x-2;
        int have_y=1+kek;
//        cout<<have_y<<" !!!"<<"\n";
        if (have_y>y){
            cout<<"No"<<"\n";
            return 0;
        }
        if ((y-have_y)%2==1){
            cout<<"No"<<"\n";
            return 0;
        }
        cout<<"Yes"<<"\n";
    }
}