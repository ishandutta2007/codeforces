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

#define x1 x1_____
#define y1 y1_____

int x1[arr];
int y1[arr];
int x2[arr];
int y2[arr];



int pref_max_x1[arr];
int pref_min_x2[arr];

int pref_max_y1[arr];
int pref_min_y2[arr];




int suf_max_x1[arr];
int suf_min_x2[arr];

int suf_max_y1[arr];
int suf_min_y2[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    }

    pref_max_x1[0]=x1[0];
    pref_min_x2[0]=x2[0];

    pref_max_y1[0]=y1[0];
    pref_min_y2[0]=y2[0];

    for (int i=1;i<n;i++){
        pref_max_x1[i]=max(pref_max_x1[i-1],x1[i]);
        pref_min_x2[i]=min(pref_min_x2[i-1],x2[i]);
        pref_max_y1[i]=max(pref_max_y1[i-1],y1[i]);
        pref_min_y2[i]=min(pref_min_y2[i-1],y2[i]);
    }




    suf_max_x1[n-1]=x1[n-1];
    suf_min_x2[n-1]=x2[n-1];

    suf_max_y1[n-1]=y1[n-1];
    suf_min_y2[n-1]=y2[n-1];

    for (int i=n-2;i>=0;i--){
        suf_max_x1[i]=max(suf_max_x1[i+1],x1[i]);
        suf_min_x2[i]=min(suf_min_x2[i+1],x2[i]);
        suf_max_y1[i]=max(suf_max_y1[i+1],y1[i]);
        suf_min_y2[i]=min(suf_min_y2[i+1],y2[i]);
    }

    for (int i=0;i<n;i++){
        int Lx=-1e9;
        int Rx=1e9;
        int Ly=-1e9;
        int Ry=1e9;
        if (i!=0){
            Lx=max(Lx,pref_max_x1[i-1]);
            Rx=min(Rx,pref_min_x2[i-1]);
            Ly=max(Ly,pref_max_y1[i-1]);
            Ry=min(Ry,pref_min_y2[i-1]);
        }
        if (i!=n-1){
            Lx=max(Lx,suf_max_x1[i+1]);
            Rx=min(Rx,suf_min_x2[i+1]);
            Ly=max(Ly,suf_max_y1[i+1]);
            Ry=min(Ry,suf_min_y2[i+1]);
        }
//        cout<<"i :: "<<i<<"\n";
//        cout<<Lx<<" "<<Rx<<"\n";
//        cout<<Ly<<" "<<Ry<<"\n";
        if (Lx<=Rx&&Ly<=Ry){
            cout<<Lx<<" "<<Ly<<"\n";
            return 0;
        }
    }
}