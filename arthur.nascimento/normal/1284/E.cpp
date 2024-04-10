#include <bits/stdc++.h>
#define maxn 1001000
#define pb insert
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
 
ll C(ll n,ll k){
    ll ans = 1;
    for(int i=0;i<k;i++) ans *= (n-i);
    for(int i=0;i<k;i++) ans /= (i+1);
    
    return ans;
}
 
struct pt {
    ll x,y;
    int quad;int id;
    pt(ll x=0,ll y=0): x(x), y(y) {}
    pt operator-(pt p){
        return pt(x-p.x,y-p.y);
    }
    ll operator%(pt p){
        return x*p.y - y*p.x;
    }
}

v[maxn];
 
ll ccw(pt a,pt b,pt c){
    return (b-a) % (c-a);
}

int pi;
pt arr[maxn];

bool cmp(pt a,pt b){
    if(a.quad != b.quad)
        return a.quad < b.quad;
    return ccw(v[pi],a,b) > 0;
}
 
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&v[i].x,&v[i].y);
    }
    
    ll ans = 0;
    
    for(pi=0;pi<n;pi++){
        int s = 0;
        for(int i=0;i<n;i++)
            if(i != pi){
                arr[s] = v[i];
                if(v[i].x >= v[pi].x && v[i].y >= v[pi].y) arr[s].quad = 1;
                else if(v[i].y > v[pi].y) arr[s].quad = 2;
                else if(v[i].x < v[pi].x) arr[s].quad = 3;
                else arr[s].quad = 4;
                arr[s].id = i;
                s++;
            }
        sort(arr,arr+s,cmp);
        
        
        for(int i=s;i<2*s;i++)
            arr[i] = arr[i-s];
            
        ll as = C(n-1,4);
            
        int r = 0;
        for(int i=0;i<s;i++){
            while(r < i) r++;
            while(r+1 < i+s && ccw(arr[i],v[pi],arr[r+1]) < 0) r++;
            
            debug("i %d pt (%lld;%lld) r %d (%c)\n",i,arr[i].x,arr[i].y,r,arr[i].id+'A');
            as -= C(r-i+1-1,3);
        }
        
        debug("pt %d ans %lld\n",pi,as);
        ans += as;
    }
    printf("%lld\n",ans);
}