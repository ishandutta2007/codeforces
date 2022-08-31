#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",max(max(max(max(max(a+b+c,a*b*c),a*b+c),a+b*c),(a+b)*c),a*(b+c)));
}