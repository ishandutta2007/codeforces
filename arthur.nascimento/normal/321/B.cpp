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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int atk[110];
int def[110];
int sumV[110];
int sumAtk[110];

int v[110];
multiset<int>S;

int atk_cnt = 0;
int def_cnt = 0;

int getAtk(){
 
 int ret = 0;
 
 for(int i=0;i<atk_cnt;i++)
         ret += atk[i]; 
 
 return ret;
}

int getSum(){
    
 int ret = 0;
 
 for(multiset<int> :: iterator it = S.begin();it != S.end(); it++)
              ret += *it;
              
 return ret;   
    
}

main(){
       
       char str[15];
       int n,m;
       
       
       
       scanf("%d%d\n",&n,&m);
       
       for(int i=0;i<n;i++){
               
               int x;
               scanf("%s %d",str,&x);
               
               if(str[0] == 'A')
                         atk[atk_cnt++] = x;
               else
                         def[def_cnt++] = x;
               
               }
       
       for(int i=0;i<m;i++){
               
               scanf("%d",v+i);
               S.insert(v[i]);
               debug("+ %d\n",v[i]);
               }
       debug("sum = %d\n",getSum());
       int resp = 0;
               
       sort(def,def+def_cnt);
       sort(atk,atk+atk_cnt);
       sort(v,v+m);
       
       sumAtk[0] = atk[0];
       
       for(int i=1;i<atk_cnt;i++)
               sumAtk[i] = sumAtk[i-1] + atk[i];
               
       sumV[m-1] = v[m-1];
       
       for(int i=m-2;i>=0;i--)
               sumV[i] = sumV[i+1] + v[i];
       
       int ok = 1;
       multiset<int> :: iterator it = S.begin();
       multiset<int> :: iterator it2 = S.begin();
       
       for(int i=0;i<def_cnt;i++){
               
               if(it == S.end()){ok = 0;break;}
               
               while(*it <= def[i]){
                         it++;
                         if(it == S.end())break;
                         }
                         
               if(it == S.end()){ok = 0;break;}
               it++;
               
           //    debug("tira %d\n",*(--it));
               debug(": %d\n",S.size());
               it2 = it;
               S.erase(--it2); 
           
               }
       
       int ok2 = 1;
       it = S.begin();
       int sum = getSum();
       debug("sum = %d\n",sum);
        debug("ok!\n");
       for(int i=0;i<atk_cnt;i++){
               
               if(it == S.end()){
                     ok2 = 0;
                     break;}
               
               
               
               while(*it < atk[i]){
                         it++;
                         if(it == S.end())break;
                         }
               if(it == S.end()){ok = 0;break;}
               it++;
               
               it2 = it;
               S.erase(--it2);
               
               }
       
       if(ok && ok2){
             resp =  sum - getAtk();
             debug("-> %d\n",resp);
       }
      
       for(int i=0;i<min(m,atk_cnt);i++){
               
               if(v[m-i-1] < atk[i])break;
               
               resp = max(resp,sumV[m-i-1] - sumAtk[i]);
               
               
               }
       printf("%d\n",resp);
       }