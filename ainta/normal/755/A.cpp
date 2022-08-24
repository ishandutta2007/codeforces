#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n<998?n+2:n-2);
}