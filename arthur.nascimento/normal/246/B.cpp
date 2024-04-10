#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

int v[100100];

main(){
       
       int n;
       cin >> n;
       
       int soma=0;
       for(int i=0;i<n;i++){       
       cin>> v[i];
       soma+=v[i];}
       
       if(soma%n==0)printf("%d",n);
       else printf("%d",n-1);
}