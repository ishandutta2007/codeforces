//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
 
pii t[10][4*arr];
 
pii merge(pii a,pii b)
{
    if (a>b){
        swap(a,b);
    }
    return mp(a.fir,min(a.sec,b.fir));
}
 
void upd(int tree,int v,int l,int r,int pos,int val)
{
    if (l==r){
        t[tree][v]=mp(val,2e9);
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        upd(tree,v*2,l,m,pos,val);
    }
    else{
        upd(tree,v*2+1,m+1,r,pos,val);
    }
    t[tree][v]=merge(t[tree][v*2],t[tree][v*2+1]);
}
 
pii get(int tree,int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return mp(2e9,2e9);
    }
    if (l>=tl&&r<=tr){
        return t[tree][v];
    }
    int m=(l+r)/2;
    return merge(
                 get(tree,v*2,l,m,tl,tr),
                 get(tree,v*2+1,m+1,r,tl,tr)
                 );
}
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
 
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        int rem_a=a;
        for (int j=0;j<9;j++){
            if (a%10==0){
                upd(j,1,1,n,i,2e9);
            }
            else{
                upd(j,1,1,n,i,rem_a);
            }
            a/=10;
        }
    }
    while (m--){
        int type;
        scanf("%d",&type);
        if (type==1){
            int pos,a;
            scanf("%d%d",&pos,&a);
            int rem_a=a;
            for (int j=0;j<9;j++){
                if (a%10==0){
                    upd(j,1,1,n,pos,2e9);
                }
                else{
                    upd(j,1,1,n,pos,rem_a);
                }
                a/=10;
            }
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r);
            ll ans=2e18;
            for (int j=0;j<9;j++){
                pii cur=get(j,1,1,n,l,r);
                ans=min(ans,(ll)cur.fir+cur.sec);
            }
            if (ans>2e9){
                cout<<-1<<"\n";
            }
            else{
                cout<<ans<<"\n";
            }
        }
    }
}