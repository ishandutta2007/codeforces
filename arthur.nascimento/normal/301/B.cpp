#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int dist[110];
int fixo[110];

int v[110];

int x[110];
int y[110];

struct vertex {
    int v,d;
    vertex(int i=0) : v(i) {
        d = dist[i];}
    bool operator<(vertex comp)const{
            return d < comp.d;}
    };

int D(int a,int b){
    return abs(x[a]-x[b]) + abs(y[a]-y[b]);}

main(){
    
        int n,d;
        scanf("%d%d",&n,&d);
        
        for(int i=1;i<n-1;i++)
            scanf("%d",v+i);
            
        for(int i=0;i<n;i++)
            scanf("%d%d",x+i,y+i);
            
        int a=0,b=100000000;
        
        while(a != b){
            
            int m = (a+b)/2;
            
            memset(dist,-1,sizeof(dist));
            memset(fixo,0,sizeof(fixo));
            
            priority_queue<vertex> Q;
            Q.push(vertex(0));
            dist[0] = m;
            
            while(!Q.empty()){
                
                vertex k = Q.top();
                Q.pop();
                
                if(fixo[k.v])
                    continue;
                    
                fixo[k.v] = 1;
                
                for(int i=0;i<n;i++)
                    if(i != k.v && D(i,k.v) * d <= dist[k.v])
                        if(dist[k.v] - D(i,k.v) * d + v[i] > dist[i])
                            dist[i] = dist[k.v] - D(i,k.v) * d + v[i],
                            Q.push(vertex(i));
                
            }
            
            
            if(fixo[n-1])
                b = m;
            else
                a = m + 1;
            
            
            
        }
        
        printf("%d\n",a);
        
}