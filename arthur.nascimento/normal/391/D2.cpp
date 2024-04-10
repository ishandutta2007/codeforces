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

int T[2002000];

void update(int idx,int val){
     idx++;
     while(idx < 2002000){
               T[idx] += val;
               idx += idx&-idx;}
}

int query(int idx){
    idx++;
    int ret = 0;
    while(idx){
               ret += T[idx];
               idx -= idx&-idx;}
    debug("bit ret %d\n",ret);
    return ret;
}

struct reta {
       int x,y,l;
       bool operator<(reta comp)const{
            return y < comp.y;}
}

r[505000];

map<int,int> mp;

int vx[2002000];

struct ev {
       int x,y,val;
       ev(int x=0,int y=0,int val=0): x(x), y(y), val(val) {}
       bool operator<(ev comp)const{
            return y < comp.y;}
}

v[2002000];

main(){
       
       int n,m;
       scanf("%d%d",&n,&m);
       
       for(int i=0;i<n+m;i++)
               scanf("%d%d%d",&r[i].x, &r[i].y, &r[i].l);
               
       sort(r+n,r+n+m);
               
       int a=0, b=100000000;
       
       while(a != b){
               
               debug("a=%d b=%d\n",a,b);
               int mid = (a+b+1)/2;
               mp.clear();
               memset(T,0,sizeof(T));
               
               int qnt = 0;
               int sz = 0;
               
               for(int i=0;i<n;i++)
                       if(2*mid <= r[i].l){
                              vx[sz++] = r[i].x;
                              v[qnt++] = ev(r[i].x, r[i].y + mid, 1);
                              v[qnt++] = ev(r[i].x, r[i].y + r[i].l - mid + 1, -1);
                              }
               
               sort(v,v+qnt);
              
               
               for(int i=n;i<n+m;i++)
                       if(2*mid <= r[i].l){
                              vx[sz++] = r[i].x + mid;
                              vx[sz++] = r[i].x + r[i].l - mid;
                              }
                              
                              
                              
                debug("ok");
               sort(vx,vx+sz);
               
               mp[vx[0]] = 0;
               for(int i=1;i<sz;i++)
                       if(vx[i] != vx[i-1])
                                mp[vx[i]] = 1 + mp[vx[i-1]];
               
            //   for(int i=0;i<qnt;i++)
            //           v[i].x = mp[v[i].x];
                         
              // for(int i=0;i<100;i++)
                //       mp[i] = i;
              
               
               int I = 0;
               int _ = n;
               
               int ok = 0;

               
               while(I < qnt){
                       
                       debug("I=%d _=%d\n",I,_);
                       
                       while(_ < n+m && r[_].y < v[I].y){
                               if(2*mid <= r[_].l)
                                      if( query( mp[r[_].x + mid] - 1) != query( mp[r[_].x + r[_].l - mid]))
                                          ok = 1;
                                      else
                                          debug("!! %d %d\n",query( mp[r[_].x + mid] - 1),query( mp[r[_].x + r[_].l - mid]));
                               debug("q. %d~%d\n",r[_].x + m, r[_].x + r[_].l - m);
                               _++;
                               
                            }
                       
                       
                       int I0 = I;
                       while(I < qnt && v[I0].y == v[I].y){
                                update(mp[v[I].x], v[I].val);
                                debug("y=%d x=%d + %d\n",v[I].y,v[I].x,v[I].val);                     
                                I++;
                                }
                                
                       
                               
                       }

               debug("ok=%d\n",ok);               
               if(ok)
                     a = mid;
               else
                   b = mid - 1;
                       
                       
               
               
               }
               
       printf("%d\n",a);

}