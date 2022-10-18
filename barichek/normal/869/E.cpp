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

#define ar (int)(3e3+10)

int f[ar][ar];

void upd(int x,int y,int val)
{
    for (int i=x;i<ar;i|=i+1){
        for (int j=y;j<ar;j|=j+1){
            f[i][j]^=val;
        }
    }
}

int get(int x,int y)
{
    int res=0;
    for (int i=x;i>=0;i&=i+1,i--){
        for (int j=y;j>=0;j&=j+1,j--){
            res^=f[i][j];
        }
    }
    return res;
}

int rnd()
{
    int res=0;
    for (int i=0;i<4*15;i+=15){
        res^=((ll(rand()&((1ll<<16)-1)))<<i);
    }
    return res;
}

map<pair<pii,pii>,int> lol;

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    srand(time(0));
    int q;
    cin>>q>>q>>q;
    while (q--){
        int type;
        cin>>type;
        if (type==1){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int kek=rnd();
            lol[mp(mp(x1,y1),mp(x2,y2))]=kek;
            upd(x1,y1,kek);
            upd(x2+1,y1,kek);
            upd(x1,y2+1,kek);
            upd(x2+1,y2+1,kek);
        }
        if (type==2){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int kek=lol[mp(mp(x1,y1),mp(x2,y2))];
            upd(x1,y1,kek);
            upd(x2+1,y1,kek);
            upd(x1,y2+1,kek);
            upd(x2+1,y2+1,kek);
        }
        if (type==3){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<(get(x1,y1)==get(x2,y2)?"Yes":"No")<<"\n";
        }
    }
}