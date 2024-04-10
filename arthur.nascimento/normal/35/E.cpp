#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define debug
using namespace std;

struct rect {
       
       int idx,xi,xf,h;
       
       rect(int idx=0,int xi=0,int xf=0,int h=0) : idx(idx) , xi(xi) , xf(xf) , h(h) {}
       
       bool operator<(rect comp)const{
            if(h == comp.h)
                 return idx < comp.idx;
                 return h < comp.h;}
                 
                 };


rect I[100100];
rect F[100100];

bool comp1(rect a,rect b){
     return a.xi < b.xi;}
bool comp2(rect a,rect b){
     return a.xf < b.xf;}

main(){
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       int n;
       scanf("%d",&n);
       
       for(int i=0;i<n;i++){
               
               scanf("%d%d%d",&I[i].h,&I[i].xi,&I[i].xf);
               
               I[i].idx = i;
               F[i] = I[i]; 
                     
               }
               
       sort(I,I+n,comp1);
       sort(F,F+n,comp2);
       
       set<rect> S;
       queue<pii> resp;
       
       int ptr1=0,ptr2=0;
       
       while(ptr1 < n || ptr2 < n){
                  
                  int h1 = (S.empty()) ? 0 : (*--S.end()).h;
                  
                  int x = (ptr1 == n) ? F[ptr2].xf : min(I[ptr1].xi,F[ptr2].xf);
                  debug("x = %d\n",x);
                  
                  while(I[ptr1].xi == x && ptr1 < n){
                                   debug("a");
                                   S.insert(rect(I[ptr1].idx,I[ptr1].xi,I[ptr1].xf,I[ptr1].h));
                                   ptr1++;}
                                   
                  while(F[ptr2].xf == x && ptr2 < n){
                                   debug("b");
                                   S.erase(rect(F[ptr2].idx,F[ptr2].xi,F[ptr2].xf,F[ptr2].h));
                                   ptr2++;}
                                   
                  int h2 = (S.empty()) ? 0 : (*--S.end()).h;
                  
                  debug("%d %d(%d)\n",h1,h2,S.size());
                  
                  if(h1 == h2)continue;
                  
                  resp.push(pii(x,h1));
                  resp.push(pii(x,h2));
                  
                  
                  
                  }
       
       printf("%d\n",resp.size());
       
       while(resp.size()){
                          printf("%d %d\n",resp.front().first,resp.front().second);
                          resp.pop();
                          }
     //  main();
       }