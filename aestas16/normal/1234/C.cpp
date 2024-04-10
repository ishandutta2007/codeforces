#include <cstdio>

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

char str[5][200010];

int main() {
    int t;scanf("%d",&t);
    while(t--) {
        int n,x=0,f=0;
        scanf("%d%s%s",&n,str[0]+1,str[1]+1);
        for(int i=1;i<=n;i++)
            if(str[x][i]>'2') {
                x=!x;
                if(str[x][i]<='2')f=1;
            }
        puts(x&&!f?"YES":"NO");
    }
    return 0; 
}
//Naive_Cat