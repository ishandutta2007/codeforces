#include <cstdio>

#define ll int

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

char str[200010];
struct fenwick
{
    int N,c[200010];
    void init(int n) {N=n;}
    int lowbit(int n) {return n&(-n);}
    void add(int x,int y) {for(;x<=N;x+=lowbit(x))c[x]+=y;}
    int sum(int x) {
        int ans=0;
        for(;x;x-=lowbit(x))ans+=c[x];
        return ans;
    }
}t;

int main() {
    int n=R(),ans=0;t.init(n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) 
        if(str[i]=='a')t.add(i,1);
    for(int i=2;i<=n;i+=2) {
        int f=t.sum(i);
        if(f!=i/2) {
            if(f>i/2) {
                if(str[i]=='a')
                    str[i]='b',t.add(i,-1);
                else if(str[i-1]=='a')
                    str[i]='b',t.add(i-1,-1);
            } else if(f<i/2) {
                if(str[i]=='b')
                    str[i]='a',t.add(i,1);
                else if(str[i-1]=='b')
                    str[i]='a',t.add(i-1,1);
            }
            ans++;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) putchar(str[i]);
    return 0;
}