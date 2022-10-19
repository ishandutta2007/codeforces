#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 2020
#define mod 1000000007
 
using namespace std;

vector<pii> ans;

struct point {
    int nil;
    long double x,y;
    point(long double x=0,long double y=0): x(x), y(y), nil(0){}
  
};

point p0;

struct line {
    long double a,b,c;
    int idx;
    void operator*=(long double m){
        a *= m;
        b *= m;
        c *= m;
    }
    bool has(point p){
        //debug("has %lf %lf %lf | %lf %lf\n",(double)a,(double)b,(double)c,(double)p.x,(double)p.y);
        long double eval = a*p.x + b*p.y + c;
        //debug("eval %lf\n",(double)eval);
        if(fabs(eval) < eps) return 1;
        return 0;
    }

};

point its(line r,line s){
    if(fabs(r.a * s.b - r.b * s.a) < eps) return p0;
    
    long double x,y;
    
    line r2=r, s2=s;
    
    if(fabs(r.a) > eps){
        long double mul = s.a / r.a;
        r *= mul;
    }
    else {
        long double mul = r.a / s.a;
        s *= mul;
    }
    
    if(fabs(r.b-s.b) < eps) return p0;
    y = (s.c-r.c)/(r.b-s.b);
    
    r = r2;
    s = s2;
    
    if(fabs(r.b) > eps){
        long double mul = s.b / r.b;
        r *= mul;
    }
    else {
        long double mul = r.b / s.b;
        s *= mul;
    }
    
    if(fabs(r.a-s.a) < eps) return p0;
    x = (s.c-r.c)/(r.a-s.a);
    
    return point(x,y);
    
}

line lines[30];
int M;
int N;

int see[1010];
int A[1010];
int B[1010];

vector<int> ans2;
int ok2;

void brute2(int k,int mask,int n){

    if(n == 0){
        ok2 = 1;
        return;
     }
     if(k == 0)
        return;

    int pega = n/k;
    if(n%k) pega++;
    
    for(int i=0;i<M;i++){
        int bitganha = (mask|see[i])^mask;
        int ganha = __builtin_popcount(bitganha);
        if(ganha >= pega){
            ans2.pb(i);
            brute2(k-1,mask|see[i],n-ganha);
            if(ok2) return;
            ans2.pop_back();
        }
    }
    
    

}

void brute(vector<line> v,int k){

    if(v.size() > 0 && k == 0){
        debug("!");
        printf("NO\n");
        exit(0);
    }

    int n = v.size();
    if(n > 25){
        
           for(int t=0;t<15;t++){
            
                int a = rand()%n;
                int b = rand()%n;
                if(a == b){
                    b++;
                    if(b == n) b = 0;
                }
                
                point u = its(v[a],v[b]);
                if(u.nil) continue;
                
                int cont = 0;
                
                for(int i=0;i<n;i++) if(v[i].has(u)) cont++;
                
                if(cont > k){
                    vector<line> vv;
                    ans.pb(pii(v[a].idx,v[b].idx));
                    for(int i=0;i<n;i++) if(!v[i].has(u)) vv.pb(v[i]);
                    brute(vv,k-1);
                    return;
                }
                
          }
          
          debug("nao achou\n");
          printf("NO\n");
          exit(0);
        
    }
    
    debug("go brute2 %d\n",n);
    N = n;
    for(int i=0;i<n;i++) lines[i] = v[i];
    
    M = 0;
    memset(see,0,sizeof(see));
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
         if(its(v[i],v[j]).nil == 0){
            
            point u = its(v[i],v[j]);
            
            A[M] = v[i].idx;
            B[M] = v[j].idx;
            
            for(int l=0;l<j;l++) if(l != i && v[l].has(u)) continue;
            
            debug("add (%d;%d) its %lf %lf\n",i,j,(double)u.x,(double)u.y);
            
            for(int l=0;l<n;l++) if(v[l].has(u)) {
                see[M] += (1<<l);
                debug("  see %d\n",l);
            }
            
            M++;
    
        }
        
    for(int i=0;i<n;i++){
        
        A[M] = v[i].idx;
        B[M] = -2;
        see[M] = (1<<i);
        M++;
        
    }
         
    ok2 = 0;  
    brute2(k,0,n);
    
    if(ok2 == 0){
        debug("brute 2 fail\n");
        printf("NO\n");
        exit(0);
    }
    
    for(int i=0;i<ans2.size();i++) ans.pb(pii(A[ans2[i]],B[ans2[i]]));


}

main(){
        
        srand(42);
        int n,k;
        scanf("%d%d",&n,&k);
        
        p0.nil = 1;
        
        vector<line> v;
        
        for(int i=0;i<n;i++){
            long long a,b,c;
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            line u;
            u.a = a;
            u.b = b;
            u.c = c;
            u.idx = i;
            v.pb(u);
         }
         
         brute(v,k);
         
         printf("YES\n%d\n",(int)ans.size());
         
         for(int i=0;i<ans.size();i++)
            printf("%d %d\n",1+ans[i].first,1+ans[i].second);
         
}