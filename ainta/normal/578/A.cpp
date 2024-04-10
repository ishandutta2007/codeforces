#include<stdio.h>
int n, a, b, r, q;
int main(){
    scanf("%d%d",&a,&b);
    if(a<b){
        printf("-1\n");
        return 0;
    }
    q = a/b, r = a%b;
    double d;
    if(q%2 == 0){
        q--, r+=b;
    }
    d=(double)r/(q+1);
    printf("%.10lf\n",b+d);
}