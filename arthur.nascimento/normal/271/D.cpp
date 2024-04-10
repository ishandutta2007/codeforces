#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

struct node {
       
       int next[26];

       
};
node v[4000400];


 char str[2020];
 char isgood[30];

main(){
       
      
       
       scanf("%s",str);
       scanf(" %s",isgood);
       
       
       int k;
       scanf("%d",&k);
       
       int resp=0;
       
       for(int i=0;i<strlen(str);i++){
               
               int S = 0;
               int ptr = 0;
               
               for(int j=i;j<strlen(str);j++){
                       
                       S += (isgood[str[j]-'a']=='0')?1:0;
                       
                       if(S > k)
                            break;
                      
                       
                     //  if(ptr -> next[str[j]-'a'] == 0){
                       if(v[ptr].next[str[j]-'a'] == 0){
                            //  resp++;
                            //  ptr -> next[str[j]-'a'] = new node;
                              v[ptr].next[str[j]-'a'] = ++resp;
                            }
                             
                       ptr = v[ptr] . next[str[j]-'a'];
                       
                       
                       }
               
               
               
               }
       
       printf("%d",resp);

       
       }