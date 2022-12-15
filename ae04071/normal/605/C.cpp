#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;

struct vec{
    lli x,y;
    vec() {}
    vec(lli x,lli y):x(x),y(y) {}
    bool operator<(const vec &rhs)const {
        return x!=rhs.x ? x<rhs.x : y<rhs.y;
    }
    vec operator-(const vec &rhs)const {
        return vec(x-rhs.x,y-rhs.y);
    }
    lli cross(const vec &rhs)const {
        return x*rhs.y-y*rhs.x;
    }
    lli len() const {
        return x*x + y*y;
    }
};

int ccw(vec a,vec b) {
    lli v=a.cross(b);
    if(v>0) return 1;
    else if(v==0) return 0;
    else return -1;
}
int ccw(vec p,vec a,vec b) {
    return ccw(a-p,b-p);
}

vector<vec> arr;
int n,a,b;

vector<vec> convex(vector<vec> &arr) {
    sort(arr.begin(),arr.end());
    sort(arr.begin()+1,arr.end(),[&](const vec &a,const vec &b) {
            int v=ccw(arr[0],a,b);
            if(v==0) return a.len() < b.len();
            else return v>0;
        });
    
    vector<vec> stk;
    for(int i=0;i<sz(arr);i++) {
        int s=sz(stk);
        while(s>=2 && ccw(stk[s-1],arr[i],stk[s-2])<=0) {
            s--; stk.pop_back();
        }
        stk.push_back(arr[i]);
    }
    return stk;
}
bool intersect(vec a, vec b, vec c, vec d,pair<double,double> &pos) {
    if(ccw(b,d)==0) return false;
    double dt = 1.0*(c-a).cross(d) / b.cross(d);
    if(dt<-1e-9 || dt>1+1e-9) return false;
    pos.fi = a.x + b.x*dt;
    pos.se = a.y + b.y*dt;
    return true;
}
double solve(vector<vec> &arr,vec pos) {
    for(int i=1;i<sz(arr)-1;i++) {
        pair<double,double> tar;
        if(intersect(arr[i],arr[i+1]-arr[i],vec(0,0),pos,tar)) {
            return pos.x / tar.fi;
        }
    }
    return -1;
}

int main() {
    vector<vec> arr;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++) {
        lli a,b;
        scanf("%lld%lld", &a, &b);
        arr.push_back(vec(a,b));
        arr.push_back(vec(a,0));
        arr.push_back(vec(0,b));
    }
    arr.push_back(vec(0,0));
    arr = convex(arr);
    printf("%.10lf\n",solve(arr, vec(a,b)));

    return 0;
}