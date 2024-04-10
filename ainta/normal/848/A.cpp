#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(n==0){
        printf("a\n");
        return 0;
    }
    int c = 0;
    while(n){
        int i, j;
        for(i=1;i*(i-1)/2<=n;i++);
        i--;
        for(j=0;j<i;j++)printf("%c",'a'+c);
        n-=i*(i-1)/2;
        c++;
    }
    printf("\n");
}