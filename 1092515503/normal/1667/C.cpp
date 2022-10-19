#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(!(n%3)){
        printf("%d\n",n/3*2);
        for(int i=0,x=0,y=0;i<n/3;i++){
            printf("%d %d\n",n-x,y+1);
            x++,y+=2;
            printf("%d %d\n",n-x,y+1);
            x+=2,y++;
        }
    }
    if(n%3==2){
        printf("%d\n",n/3*2+1);
        int x=0,y=1;
        for(int i=0;i<n/3;i++){
            printf("%d %d\n",n-x,y+1);
            x+=2,y++;
            printf("%d %d\n",n-x,y+1);
            x++,y+=2;
        }
        printf("%d %d\n",n-x,y+1);
    }
    if(n%3==1){
        printf("%d\n",n/3*2+1);
        int x=0,y=0;
        for(int i=0;i<n/3;i++){
            printf("%d %d\n",n-x,y+1);
            x++,y+=2;
            printf("%d %d\n",n-x,y+1);
            x+=2,y++;
        }
        printf("%d %d\n",n-x,y+1);
    }
    return 0;
}