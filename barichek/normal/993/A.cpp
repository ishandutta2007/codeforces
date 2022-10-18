#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

ld sqr(ld a)
{
    return a*a;
}

ld get(ld x,ld y)
{
    ld res=0;
    for (int i=0;i<4;i++){
        ld kek=abs(x-x1[i])+abs(y-y1[i]);
        res+=kek;
    }
    return res;
}

bool in(ld x,ld y)
{
    return abs(get(x,y)-get(x1[0],y1[0]))<eps;
}

ld kek=1e-3;

void dooo1()
{
    for (int i=0;i<4;i++){
        int to=(i+1)%4;
        if (x2[i]>x2[to]){
            if (y2[i]>y2[to]){
                ld xx=x2[i];
                ld yy=y2[i];
                while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                    if (in(xx,yy)){
                        cout<<"YES"<<"\n";
                        exit(0);
                    }
                    xx-=kek;
                    yy-=kek;
                }
            }
            else{
                ld xx=x2[i];
                ld yy=y2[i];
                while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                    if (in(xx,yy)){
                        cout<<"YES"<<"\n";
                        exit(0);
                    }
                    xx-=kek;
                    yy+=kek;
                }
            }
        }
        else{
            if (y2[i]>y2[to]){
                ld xx=x2[i];
                ld yy=y2[i];
                while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                    if (in(xx,yy)){
                        cout<<"YES"<<"\n";
                        exit(0);
                    }
                    xx+=kek;
                    yy-=kek;
                }
            }
            else{
                ld xx=x2[i];
                ld yy=y2[i];
                while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                    if (in(xx,yy)){
                        cout<<"YES"<<"\n";
                        exit(0);
                    }
                    xx+=kek;
                    yy+=kek;
                }
            }
        }
    }
}

void dooo2()
{
    for (int i=0;i<4;i++){
        int to=(i+1)%4;
        if (x2[i]>x2[to]){
            ld xx=x2[i];
            ld yy=y2[i];
            while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                if (in(xx,yy)){
                    cout<<"YES"<<"\n";
                    exit(0);
                }
                cout<<xx<<" "<<yy<<" "<<get(xx,yy)<<" "<<get(x1[0],y1[0])<<" 11!!\n";
                xx-=kek;
            }
        }
        elif (x2[i]<x2[to]){
            ld xx=x2[i];
            ld yy=y2[i];
            while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                if (in(xx,yy)){
                    cout<<"YES"<<"\n";
                    exit(0);
                }
                xx+=kek;
                cout<<xx<<" "<<yy<<" "<<get(xx,yy)<<" "<<get(x1[0],y1[0])<<" 22!!\n";
            }
        }
        elif (y2[i]<y2[to]){
            ld xx=x2[i];
            ld yy=y2[i];
            while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                if (in(xx,yy)){
                    cout<<"YES"<<"\n";
                    exit(0);
                }
                yy+=kek;
                cout<<xx<<" "<<yy<<" "<<get(xx,yy)<<" "<<get(x1[0],y1[0])<<" 33!!\n";
            }
        }
        elif (y2[i]>y2[to]){
            ld xx=x2[i];
            ld yy=y2[i];
            while (abs(xx-x2[to])+abs(yy-y2[to])>eps){
                if (in(xx,yy)){
                    cout<<"YES"<<"\n";
                    exit(0);
                }
                yy-=kek;
                cout<<xx<<" "<<yy<<" "<<get(xx,yy)<<" "<<get(x1[0],y1[0])<<" 44!!\n";
            }
        }
    }
}

void lol(int& a,int& b)
{
    int aa=a;
    int bb=b;
    a=aa+bb;
    b=aa-bb;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<4;i++){
        cin>>x1[i]>>y1[i];
    }
    for (int i=0;i<4;i++){
        cin>>x2[i]>>y2[i];
    }
    dooo1();
    for (int i=0;i<4;i++){
        swap(x1[i],x2[i]);
        swap(y1[i],y2[i]);
    }
    for (int i=0;i<4;i++){
        lol(x1[i],y1[i]);
        lol(x2[i],y2[i]);
    }
//    for (int i=0;i<4;i++){
//        cout<<x1[i]<<" "<<y1[i]<<"\n";
//    }
//    for (int i=0;i<4;i++){
//        cout<<x2[i]<<" "<<y2[i]<<"\n";
//    }
//    return 0;
    dooo1();
    cout<<"NO"<<"\n";
}