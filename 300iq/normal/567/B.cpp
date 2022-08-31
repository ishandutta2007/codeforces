#include <iostream>
#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;
int r[1000000];
int n;
int z[1000000];
int counter = 0;
int index;
int ans=0;
char buff;
int main()
{
cin>>n;
for(int i = 0; i<n; i++){
    cin>>buff>>index;
    if(buff=='+'){
    r[index]=1;
    counter+=1;
    ans = max(ans, counter);
    }
    else if(buff =='-'&&r[index]==1){
        r[index]=0;
        counter-=1;

    }
      else if(buff =='-'&&r[index]==0){
        r[index]=0;
        ans += 1;
    }



}



cout<<ans;



}