#include<cstdio>
int abs(int x) {return x>0?x:-x;}
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (a!=c && b!=d && abs(d-b)!=abs(a-c)) {printf("-1"); return 0;}
    if (a==c) printf("%d %d %d %d",d-b+a,b,d-b+a,d);
    else if (b==d) printf("%d %d %d %d",a,c-a+b,c,c-a+d);
    else printf("%d %d %d %d",a,d,c,b);
}