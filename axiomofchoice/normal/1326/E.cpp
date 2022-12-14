#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const int N=300010;
int pos[N],q[N],n;

//********************

struct seg{ //init()tr->sth()
    #define U(x,y) max(x,y) //
    #define a0 -inf //
    void toz(ll x){z+=x,state=1;} //
    void toa(){a+=z,z=0,state=0;} //z
    ll a,z; bool state; //
    int l,r;
    seg *lc,*rc;
    void init(int,int);
    void up(){
        a=U(lc->a,rc->a);
    }
    void down(){
        if(!state)return;
        if(l<r){
            lc->toz(z);
            rc->toz(z);
        }
        toa();
    }
    void update(int x,int y,ll k){
        x=max(x,l); y=min(y,r); if(x>y){down();return;}
        if(x==l && y==r){
            toz(k);
            down();
            return;
        }
        down();
        lc->update(x,y,k);
        rc->update(x,y,k);
        up();
    }
    ll query(int x,int y){
        x=max(x,l); y=min(y,r); if(x>y)return a0;
        down();
        if(x==l && y==r)
            return a;
        return U(lc->query(x,y),rc->query(x,y));
    }
}tr[N*2],*pl;
void seg::init(int _l,int _r){
    l=_l,r=_r;
    state=0;
    if(l==r){
        a=0;
        return;
    }
    int m=(l+r)>>1;
    lc=++pl; lc->init(l,m);
    rc=++pl; rc->init(m+1,r);
    up();
}
void init(int l,int r){
    pl=tr;
    tr->init(l,r);
}

//********************

void push_value(int p){
    tr->update(1,p,1);
}
void push_bomb(int p){
    tr->update(1,p,-1);
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    n=read();
    repeat(i,1,n+1)pos[read()]=i;
    repeat(i,1,n+1)q[i]=read();
    int ans=n;
    init(1,n);
    push_value(pos[ans]);
    cout<<ans<<' ';
    repeat(i,1,n){
        push_bomb(q[i]);
        while(tr->query(1,n)<=0){
            ans--;
            push_value(pos[ans]);
        }
        cout<<ans<<' ';
    }
    return 0;
}