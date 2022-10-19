#include <bits/stdc++.h>
#define maxn 2020
#define ll long long
#define debug printf
#define pb push_back
#define pii pair<int,int>
using namespace std;


struct pt {
    ll x,y;
    int id;
    pt(ll x=0,ll y=0,int id=0): x(x), y(y), id(id) {}
    pt operator- (pt p){
        return pt(x-p.x,y-p.y);
    }
    ll operator% (pt p){
        return x*p.y - y*p.x;
    }
};

pt oo;
int quad(pt p){
    if(p.y >= oo.y){
        
        return 1;
    }
    return 2;
}

int to[maxn];

ll ccw(pt a,pt b,pt c){
    return (c-a) % (b-a);
}


int cic[maxn];
int mrk[maxn];

int pai[maxn];
int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

main(){
    
    int n;
    scanf("%d",&n);
    
    vector<pt> v;
    
    for(int i=0;i<n;i++){
        pt a;
        scanf("%lld%lld%d",&a.x,&a.y,&to[i]), to[i]--;
        a.id = i;
        if(to[i] != i)
            v.pb(a);
    }
    
    if(v.size() == 0){
        printf("0\n");
        return 0;
    }
    
    int o = 0;
    for(int i=0;i<v.size();i++){
        
        if(v[i].x < v[o].x) o = i;
        if(v[i].x == v[o].x && v[i].y < v[o].y) o = i;
     
    }
    
    oo = v[o];
    swap(v[o],v[0]);
    
    sort(++v.begin(),v.end(),[](pt i,pt j){
        if(quad(i) != quad(j))
            return quad(i) < quad(j);
        return ccw(oo,i,j) > 0;
    });
    
    int cur = 0;
    for(int i=0;i<n;i++){
        if(mrk[i]) continue;
        int u = to[i];
        cic[i] = cur;
        while(u != i){
            cic[u] = cur;
            u = to[u];
        }
        cur++;
    }
    
    for(int i=0;i<n;i++)
        pai[i] = cic[i];
    
    vector<pii> ans;
    
    for(int i=2;i<v.size();i++)
        if(find(to[v[i].id]) != find(to[v[i-1].id])){
            swap(to[v[i].id], to[v[i-1].id]);
            pai[find(v[i].id)] = find(v[i-1].id);
            ans.pb({v[i].id,v[i-1].id});
        }
        
    while(to[v[0].id] != v[0].id){
        ans.pb({v[0].id,to[v[0].id]});
        swap(to[v[0].id], to[to[v[0].id]]);
    }
    
    printf("%d\n",ans.size());
    
    for(pii i : ans)
        printf("%d %d\n",1+i.first,1+i.second);
    
}