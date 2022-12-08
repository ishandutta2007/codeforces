#include<cstdio>
inline int abs(int x){return x>0?x:-x;}
int main(){
    int a,b,c,ans=999999999;
    scanf("%d%d%d",&a,&b,&c);
    for (int i=1;i<=100;i++){
        if (ans>abs(a-i)+abs(b-i)+abs(c-i)) ans=abs(a-i)+abs(b-i)+abs(c-i);
    }
    printf("%d\n",ans);
    return 0;
}