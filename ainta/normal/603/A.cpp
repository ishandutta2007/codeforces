#include<stdio.h>
#include<algorithm>
using namespace std;
int n, R, c;
char p[101000];
int main(){
    int i;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;i<n-1;i++){
        if(p[i]!=p[i+1]){
            R++;
        }
        else{
            c++;
        }
    }
    printf("%d\n",R+min(c,2)+1);
}