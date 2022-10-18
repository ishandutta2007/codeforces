#include <cstdio>
#include <cstring>

#define reg register

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

struct fenwick {
    int N,c[100010];
    void init(int n) {N=n;}
    int lowbit(int n) {return n&(-n);}
    void add(int x,int y) {
        for(;x<=N;x+=lowbit(x))c[x]+=y;
    }
    int sum(int x) {
        int ans=0;
        for(;x;x-=lowbit(x))ans+=c[x];
        return ans;
    }
}tr[30];
char str[100010];

int main() {
    scanf("%s",str);
    int len=strlen(str),m=R();
    for(int i=0;i<=26;i++) tr[i].init(len);
    for(int i=0;i<len;i++) tr[str[i]-'a'+1].add(i+1,1);
    while(m--) {
        int opt=R(),l=R(),r,ans=0;char c[5];
        if(opt==1) {
            scanf("%s",c);
            tr[str[l-1]-'a'+1].add(l,-1);
            tr[c[0]-'a'+1].add(l,1);
            str[l-1]=c[0];
        } else {
            fr(r);
            for(int i=1;i<=26;i++) {
                int f=tr[i].sum(r)-tr[i].sum(l-1);
                if(f>0)ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}