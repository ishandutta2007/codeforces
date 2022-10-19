#include<iostream>
#include<cstdio>
using namespace std;
int ans,n;
char a[514]={'D','A','C','B'},x,y;
int main(){
    scanf("%d",&n);
    if(a[n%4]>a[(n+1)%4]){
        x=a[(n+2)%4];
        y=a[(n+1)%4];
        if(x>y) printf("1 %c",a[(n+1)%4]);
        else printf("2 %c",a[(n+2)%4]);
    }
        
    else{
        if(a[n%4]<a[(n+2)%4]) printf("0 %c",a[n%4]);
        else printf("2 %c",a[(n+2)%4]);
    }
    return 0;
}