#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long v[100100];
long long n,x;

long long f(long long a,long long b){
    if(b>=a)return b-a;
    return n-(a-b);}

main(){
       
       long long best=-1;
       
       cin>>n>>x;
       x--;
       
       for(int i=0;i<n;i++){
               cin>>v[i];
               if(best==-1)best=i;
               if(v[i] < v[best])best=i;
               if(v[i]==v[best] && f(i,x) < f(best,x))best=i;
               
               }
               
       for(int i=0;i<n;i++){
               
               if(i==best)
               cout<<(n*v[best]+f(best,x));
               else
               cout<<(v[i]-v[best]-((f(best,i) <= f(best,x))?1:0));
               if(i!=n-1)printf(" ");
               }
          //  main();
               }