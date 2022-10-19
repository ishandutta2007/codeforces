#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int M[4][4];

bool check(){
     
     for(int i=0;i<=2;i++)
             for(int j=0;j<=2;j++)
                     if(M[i][j] == M[i+1][j] && M[i][j] == M[i][j+1] && M[i][j] == M[i+1][j+1])return 1;
                     
                     
     return false;
     
     }
     
main(){
       
       
        for(int i=0;i<=3;i++){
             for(int j=0;j<=3;j++)
                     scanf("%c",&M[i][j]);
                     getchar();
                     }
             
        int resp = check() ;
                     
         for(int i=0;i<=3;i++){
             for(int j=0;j<=3;j++) {
             
             M[i][j] = (M[i][j]=='.')?'#':'.';
             resp |= check();
             M[i][j] = (M[i][j]=='.')?'#':'.';
             
             }}
             
         printf("%s\n",resp?"YES":"NO");
      
             }