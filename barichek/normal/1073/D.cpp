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

pii operator+(pii a,pii b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

int a[arr];
pii t[4*arr];

void build(int v,int l,int r)
{
    if (l==r){
        t[v]=mp(a[l],1);
        return;
    }

    int m=(l+r)/2;

    build(v*2,l,m);
    build(v*2+1,m+1,r);

    t[v]=t[v*2]+t[v*2+1];
}

void upd(int v,int l,int r,int pos,pii val)
{
    if (l==r){
        t[v]=val;
        return;
    }

    int m=(l+r)/2;

    if (pos<=m){
        upd(v*2,l,m,pos,val);
    }
    else{
        upd(v*2+1,m+1,r,pos,val);
    }

    t[v]=t[v*2]+t[v*2+1];
}

pii get(int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return mp(0,0);
    }
    if (l>=tl&&r<=tr){
        return t[v];
    }

    int m=(l+r)/2;

    return
        get(v*2,l,m,tl,tr)+
        get(v*2+1,m+1,r,tl,tr);
}

int get_kek(int v,int l,int r,int value)
{
    if (l==r){
        return l;
    }

    int m=(l+r)/2;

    if (t[v*2].fir<=value){
        return get_kek(v*2+1,m+1,r,value-t[v*2].fir);
    }
    else{
        return get_kek(v*2,l,m,value);
    }
}

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
    }
    build(1,1,n);
    int ans=0;
    int cur_live=n;
    int sum_live=0;
    for (int i=1;i<=n;i++){
        sum_live+=a[i];
    }
    int cur_pos=1;

    while (cur_live!=0){
        if (cur_live==1){
            ans+=t/sum_live;
            cur_live--;
            sum_live=0;
        }
        else{
            int lolus=t/sum_live;
            ans+=lolus*cur_live;
            t-=lolus*sum_live;

            int value_for_del=0;

            pii kek=get(1,1,n,cur_pos,n);
            if (kek.fir>t){
                pii lol=(cur_pos==1?mp(0ll,0ll):get(1,1,n,1,cur_pos-1));
                int pos=get_kek(1,1,n,t+lol.fir);
                value_for_del=get(1,1,n,pos,pos).fir;
                if (cur_pos==pos){
                    upd(1,1,n,cur_pos,mp(0,0));
                }
                else{
                    pii kekus=get(1,1,n,cur_pos,pos-1);
                    ans+=kekus.sec;
                    t-=kekus.fir;
                    upd(1,1,n,pos,mp(0,0));
                    cur_pos=pos;
                }
            }
            else{
                pii lol=get(1,1,n,cur_pos,n);
                int pos=get_kek(1,1,n,t-lol.fir);
                value_for_del=get(1,1,n,pos,pos).fir;

                pii lol1=(pos==1?mp(0ll,0ll):get(1,1,n,1,pos-1));

                ans+=lol.sec+lol1.sec;

                t-=lol.fir+lol1.fir;

                upd(1,1,n,pos,mp(0,0));
                cur_pos=pos;
            }

            cur_live--;
            sum_live-=value_for_del;
        }
    }
    cout<<ans<<"\n";
}