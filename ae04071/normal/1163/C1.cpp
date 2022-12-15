#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;

inline lli _abs(lli a) {
    return a<0 ? -a : a;
}
struct vec{
    lli x,y;
    vec() {}
    vec(lli x,lli y):x(x),y(y){}
    bool operator<(const vec &rhs)const {
        return x!=rhs.x ? x<rhs.x : y<rhs.y;
    }
    bool operator==(const vec &rhs)const {
        return x==rhs.x && y==rhs.y;
    }
    vec operator+(const vec &rhs)const {
        return vec(x+rhs.x,y+rhs.y);
    }
    vec operator-(const vec &rhs)const {
        return vec(x-rhs.x,y-rhs.y);
    }
    lli cross(const vec &rhs)const {
        return x*rhs.y-y*rhs.x;
    }
}arr[1000];

int n;

int ccw(const vec a, const vec b) {
    lli v=a.cross(b);
    if(v>0) return 1;
    else if(v==0) return 0;
    else return -1;
}
int ccw(const vec p,const vec a, const vec b) {
    return ccw(a-p,b-p);
}

struct seg{
    vec a,p;
    seg() {}
    seg(vec _a,vec _b){
        a=_b-_a;
        p=_a;
        if(a.x<0) {
            a.x=-a.x;
            a.y=-a.y;
        }
        if(a.x==0 && a.y<0) {
            a.y = -a.y;
        }
        lli g=__gcd(_abs(a.x),_abs(a.y));
        a.x/=g; a.y/=g;
    }
    bool operator<(const seg &rhs)const {
        if(!(a==rhs.a)) return a<rhs.a;
        else {
            vec b=p+a,rb=rhs.p+rhs.a;
            return ccw(p,b,rb)>0;
        }
    }
    bool operator==(const seg &rhs)const {
        if(!(a==rhs.a)) return false;
        vec b=p+a,rb=rhs.p+rhs.a;
        return ccw(p,b,rb)==0;
    }
};

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",&arr[i].x,&arr[i].y);

    vector<seg> a;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) a.push_back(seg(arr[i],arr[j]));
    sort(a.begin(),a.end());
    
    int c=0;
    for(int i=0;i<sz(a);i++) {
        if(i==0 || !(a[i]==a[c-1])) {
            a[c++]=a[i];
        }
    }
    lli ans=0;
    a.resize(c);
    for(int i=0,j;i<sz(a);i=j) {
        for(j=i;j<sz(a) && a[i].a==a[j].a;j++);
        ans += 1ll*(sz(a)-j)*(j-i);
    }
    printf("%lld\n",ans);
    
    return 0;
}