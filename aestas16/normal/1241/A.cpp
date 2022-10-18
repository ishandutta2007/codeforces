#include <cstdio>

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

int main() {
    int q=R();
    while(q--) {
        int n=R();
        if(n%2==0&&n>2)printf("0\n");
        else printf("%d\n",(n/2+1)*2-n);
    }
    return 0;
}