#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct frac{
    int p,q;
    bool operator<(const frac&x)const{
        return 1LL*p*x.q<1LL*x.p*q;
    }
    bool operator==(const frac&x)const{
        return 1LL*p*x.q==1LL*x.p*q;
    }
};

int n,x1,y1,x2,y2;
frac l={0,1},r={1000000,1};

void updlo(int a,int b,int v){
    assert(a<=b&&v>0);
    frac it={b-a,v};
    if(l<it)l=it;
}

void updhi(int a,int b,int v){
    assert(a<=b&&v>0);
    frac it={b-a,v};
    if(it<r)r=it;
}

int main(){
    cin>>n>>x1>>y1>>x2>>y2;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    for(int i=0;i<n;i++){
        int x,y,vx,vy;
        cin>>x>>y>>vx>>vy;
        if((y==y1||y==y2)&&vy==0)return cout<<-1,0;
        if((x==x1||x==x2)&&vx==0)return cout<<-1,0;
        if(x<x1){
            if(vx<=0)return cout<<-1,0;
            updlo(x,x1,vx);
            updhi(x,x2,vx);
        }else if(x>x2){
            if(vx>=0)return cout<<-1,0;
            updlo(x2,x,-vx);
            updhi(x1,x,-vx);
        }else if(vx>0){
            updhi(x,x2,vx);
        }else if(vx<0){
            updhi(x1,x,-vx);
        }
        if(y<y1){
            if(vy<=0)return cout<<-1,0;
            updlo(y,y1,vy);
            updhi(y,y2,vy);
        }else if(y>y2){
            if(vy>=0)return cout<<-1,0;
            updlo(y2,y,-vy);
            updhi(y1,y,-vy);
        }else if(vy>0){
            updhi(y,y2,vy);
        }else if(vy<0){
            updhi(y1,y,-vy);
        }
    }
    if(r<l||r==l)return cout<<-1,0;
    cout.precision(12);
    cout<<fixed<<(ld)l.p/l.q;
}