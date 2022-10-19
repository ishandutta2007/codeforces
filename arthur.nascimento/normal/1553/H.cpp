#include <bits/stdc++.h>
#define maxn 150150
#define maxA 1001000
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug 
#define inf 10000000
using namespace std;

struct bla {
    vector<int> ans, mn, mx;
    bla(int a=0,int m=0,int M=0){
        ans.pb(a);
        mn.pb(m);
        mx.pb(M);
    }
};

bla solve(int k,vector<int> v){
    if(k == 0){
        if(v.size()) return bla(inf,v[0],v[0]);
        else return bla(inf,inf,-inf);
    }
    vector<int> L,R;
    for(int i : v){
        if(i & (1<<(k-1)))
            R.pb(i);
        else
            L.pb(i);
    }
    
    bla l = solve(k-1,L), r = solve(k-1,R);
    
    bla res;
    res.ans.resize(1<<k);
    res.mx.resize(1<<k);
    res.mn.resize(1<<k);
    
    for(int i=0;i<(1<<k);i++){
        
        int mid = (1<<(k-1));
        
        if(i < mid)
            res.ans[i] = min( min(l.ans[i],r.ans[i]) , r.mn[i] - l.mx[i]),
            res.mx[i] = max( r.mx[i], l.mx[i]),
            res.mn[i] = min( r.mn[i], l.mn[i]);
        else
            res.ans[i] = min( min(l.ans[i-mid],r.ans[i-mid]) , l.mn[i-mid] - r.mx[i-mid] + 2*mid),
            res.mx[i] = max( r.mx[i-mid] - mid, l.mx[i-mid] + mid),
            res.mn[i] = min( r.mn[i-mid] - mid, l.mn[i-mid] + mid);
            
        
    }
    
    for(int i : v) debug("%d ",i);
    debug("\nans: "); for(int i : res.ans) debug("%d ",i);
    debug("\nmn: "); for(int i : res.mn) debug("%d ",i);
    debug("\nmx: "); for(int i : res.mx) debug("%d ",i);
    debug("\n\n");
    
    return res;
    
}

main(){
    
    int k,n;
    scanf("%d%d",&n,&k);
    
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        v.pb(a);
    }
    
    sort(v.begin(), v.end());
    bla x = solve(k,v);
    for(int i=0;i<(1<<k);i++)
        printf("%d ",x.ans[i]);
    printf("\n");
    
}