#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
struct vertex{
    ll ans;
    vector< pair<int,int> > pre,suf;
};
vertex t[4*maxn],nth;
int n,q,x,a[maxn];
vertex Merge( vertex a, vertex b){
    
    vertex c;
    if(a.ans==-1)
        return b;
    if(b.ans==-1)
        return a;
    c.ans=a.ans+b.ans;
    for(auto s: a.suf)
        for(auto p: b.pre)
            if( (s.f|p.f)>=x )
                c.ans+=1ll*s.s*p.s;
    c.pre=a.pre;
    for(auto p: b.pre){
        if( (c.pre[c.pre.size()-1].f|p.f)==c.pre[c.pre.size()-1].f )
            c.pre[c.pre.size()-1].s+=p.s;
        else
            c.pre.pb({(c.pre[c.pre.size()-1].f|p.f),p.s});    
    }
    c.suf=b.suf;
    for(auto s: a.suf){
        if( (c.suf[c.suf.size()-1].f|s.f)==c.suf[c.suf.size()-1].f )
            c.suf[c.suf.size()-1].s+=s.s;
        else
            c.suf.pb({(c.suf[c.suf.size()-1].f|s.f),s.s});    
    }

    return c;
    
}
void up(int v,int tl, int tr, int pos, int val){
    if(tl==tr){
        t[v].ans=(val>=x);
        t[v].pre.clear();
        t[v].pre.pb({val,1});
        t[v].suf.clear();
        t[v].suf.pb({val,1});
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)               
        up(v+v,tl,tm,pos,val);
    else
        up(v+v+1,tm+1,tr,pos,val);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void build(int v,int tl, int tr){
    if(tl==tr){
        t[v].ans=(a[tl]>=x);
        t[v].pre.clear();
        t[v].pre.pb({a[tl],1});
        t[v].suf.clear();
        t[v].suf.pb({a[tl],1});
        return;
    }
    int tm=(tl+tr)/2;
    build(v+v,tl,tm);
    build(v+v+1,tm+1,tr);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
vertex get(int v,int tl, int tr,int l, int r){
    vertex a,b,c;
    if(l>r)
        return nth;
    if(tl==l && tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    a=get(v+v,tl,tm,l,min(tm,r));
    b=get(v+v+1,tm+1,tr,max(tm+1,l),r);
    c=Merge(a,b);
    return c;
}
int main(){
    nth.ans=-1;
    scanf("%d%d%d",&n,&q,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(q--){
        int type,a,b;
        scanf("%d%d%d",&type,&a,&b);
        if(type==1)
            up(1,1,n,a,b);    
        else
            printf("%I64d\n",get(1,1,n,a,b).ans);
    }
}