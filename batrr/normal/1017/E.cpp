#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
const double eps=1e-9;

struct pt {
    int x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return 1ll*a.x*(b.y-c.y)+1ll*b.x*(c.y-a.y)+1ll*c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

ll dis( pt a,pt b){
    return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);
}
pair< double , double > get( pt q,pt w,pt e){
    ll a,b,c;  
    a=dis(q,w);
    b=dis(q,e);
    c=dis(w,e);
    return {1.0*(a+b-c)/( 2*sqrtl(a)*sqrtl(b) ), sqrtl(a) };
}
vector<int> z_function ( vector< pair< double , double > > s) {
    int n = (int) s.size();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && fabs(s[z[i]].f-s[i+z[i]].f) < eps && fabs(s[z[i]].s-s[i+z[i]].s) < eps )
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    int n,m;
    scanf("%d%d",&n,&m);
   
    vector< pt > a,b;
    
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a.pb({x,y});
    }
    convex_hull(a);
    
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        b.pb({x,y});
    }
    convex_hull(b);
    
    if( a.size()!=b.size() ){
        puts("NO");
        return 0;
    }
    
    vector< pair< double , double >  > s,t;
    
    for(int i=0;i<a.size();i++)
        s.pb(get(a[i],a[(i-1+a.size())%a.size()],a[(i+1)%a.size()]) );
    
    for(int i=0;i<b.size();i++)
        t.pb(get(b[i],b[(i-1+b.size())%b.size()],b[(i+1)%b.size()]) );
                            
    t.pb({-1e9,-1e9});    
    for(int i=0;i<a.size();i++)
        t.pb(s[i]);
    for(int i=0;i<a.size();i++)
        t.pb(s[i]);
    vector<int> z=z_function(t);
    
    int good=0;
    for(int i=0;i<z.size();i++)
        if( z[i]>=b.size() )
            good++;
    
    if( good<=0 )
        puts("NO");
    else
        puts("YES");
    
}