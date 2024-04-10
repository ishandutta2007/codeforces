#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;


main(){
       
       int n;
       cin >> n;
       if(n==1 || n==2){printf("-1");return 0;}
       
       for(int i = n;i>0;i--)
       printf("%d ",i);
       
       
       
       }