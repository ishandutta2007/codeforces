#include<cstdio>
#include<cstring>
const int N=100005;
int t,l1,l2,l,flag;
char a[22],b[22];
inline bool judge(int x,int y){
    for(int i=0;i<l;i++)
        if(a[x+i]!=b[y+i]) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",a,b);
        l1=strlen(a); l2=strlen(b);
        flag=1;
        for(l=l1;l>=0&&flag;l--)
            for(int x=0;x<=l1-l&&flag;x++)
                for(int y=0;y<=l2-l&&flag;y++)
                    if(judge(x,y)) flag=0;
        printf("%d\n",l1+l2-(l+1)*2);
    }
    return 0;
}