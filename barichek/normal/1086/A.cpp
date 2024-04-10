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

int d(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

int d(pii a,pii b)
{
    return d(a.fir,a.sec,b.fir,b.sec);
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    pii a[3];
    for (int i=0;i<3;i++){
        cin>>a[i].fir>>a[i].sec;
    }
    sort(a,a+3);
    vector<pii> ans(0);
    if (a[0].sec<=a[2].sec){
        if (d(a[0],a[1])+d(a[1],a[2])==d(a[0],a[2])){
            int x=a[0].fir;
            int y=a[0].sec;
            ans.pb(mp(x,y));
            while (x!=a[1].fir||y!=a[1].sec){
                if (x<a[1].fir){
                    x++;
                }
                else{
                    y++;
                }
                ans.pb(mp(x,y));
            }
            while (x!=a[2].fir||y!=a[2].sec){
                if (x<a[2].fir){
                    x++;
                }
                else{
                    y++;
                }
                ans.pb(mp(x,y));
            }
        }
        else{
            if (a[1].sec<a[0].sec){
                for (int i=a[0].fir;i<=a[2].fir;i++){
                    ans.pb(mp(i,a[0].sec));
                }
                for (int i=a[0].sec+1;i<=a[2].sec;i++){
                    ans.pb(mp(a[2].fir,i));
                }
                for (int i=a[1].sec;i<a[0].sec;i++){
                    ans.pb(mp(a[1].fir,i));
                }
            }
            else{
                for (int i=a[0].sec;i<=a[2].sec;i++){
                    ans.pb(mp(a[0].fir,i));
                }
                for (int i=a[0].fir+1;i<=a[2].fir;i++){
                    ans.pb(mp(i,a[2].sec));
                }
                for (int i=a[2].sec+1;i<=a[1].sec;i++){
                    ans.pb(mp(a[1].fir,i));
                }
            }
        }
    }
    else{
        if (d(a[0],a[1])+d(a[1],a[2])==d(a[0],a[2])){
            int x=a[0].fir;
            int y=a[0].sec;
            ans.pb(mp(x,y));
            while (x!=a[1].fir||y!=a[1].sec){
                if (x<a[1].fir){
                    x++;
                }
                else{
                    y--;
                }
                ans.pb(mp(x,y));
            }
            while (x!=a[2].fir||y!=a[2].sec){
                if (x<a[2].fir){
                    x++;
                }
                else{
                    y--;
                }
                ans.pb(mp(x,y));
            }
        }
        else{
            if (a[1].sec<a[2].sec){
                for (int i=a[0].fir;i<=a[2].fir;i++){
                    ans.pb(mp(i,a[2].sec));
                }
                for (int i=a[2].sec+1;i<=a[0].sec;i++){
                    ans.pb(mp(a[0].fir,i));
                }
                for (int i=a[1].sec;i<a[2].sec;i++){
                    ans.pb(mp(a[1].fir,i));
                }
            }
            else{
                for (int i=a[2].sec;i<=a[0].sec;i++){
                    ans.pb(mp(a[2].fir,i));
                }
                for (int i=a[0].fir;i<a[2].fir;i++){
                    ans.pb(mp(i,a[0].sec));
                }
                for (int i=a[0].sec+1;i<=a[1].sec;i++){
                    ans.pb(mp(a[1].fir,i));
                }
            }
        }
    }

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}