#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

stack<int> ans;

main(){
       
       int n;
       scanf("%d",&n);
       
       if(n%4 == 2 || n%4 == 3){
              printf("-1\n");
              return 0;}
       
       int m=n;
       
              
       int ri=1,rf=n;
       
       while(m>3){
                  
                  printf("%d %d ",ri+1,rf);
                  
                  ans.push(rf-1);
                  ans.push(ri);
                  
                  ri+=2;
                  rf-=2;
                  m-=4;
                  }
              
       if(m)printf("%d ",ri);
       
       while(!ans.empty()){
                           printf("%d ",ans.top());
                           ans.pop();
                           }
               
                  }