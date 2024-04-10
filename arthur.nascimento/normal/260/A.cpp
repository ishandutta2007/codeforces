#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


main(){
       
       int a,b,n;
       scanf("%d%d%d",&a,&b,&n);
       
     
             int ok=0;
           
             
             for(int i=0;i<=9;i++){
                     if((a*10+i)%b==0){ok=1;printf("%d%d",a,i);break;}
                     }
             
             if(!ok){printf("-1\n");return 0;}
             
             for(int i=1;i<n;i++)
                     printf("0");
                     
                     printf("\n");
                     
             
             
 
                      
       }