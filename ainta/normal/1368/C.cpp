#include<cstdio>
#include<algorithm>
using namespace std;
char pp[11]="codeforces";
int main(){
    int n, i;
    scanf("%d",&n);
    printf("%d\n",(n+1)*3+1);
    for(i=0;i<=n;i++){
        printf("%d %d\n",i,i);
        printf("%d %d\n",i+1,i);
        printf("%d %d\n",i,i+1);
    }
    printf("%d %d\n",n+1,n+1);
}