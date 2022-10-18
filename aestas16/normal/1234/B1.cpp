#include <cstdio>
#include <map>

#define reg register

using std::map;

namespace FastIO {
    char B[1<<20],*S=B,*T=B,D[1<<25],*A=D-1,F=0;
    template<class T>inline void fr(reg T &a) {
    #ifdef ONLINE_JUDGE
        !F?fread(B,1,1<<20,stdin),F=1:0;
        reg char *c=S,f=0;a=0;
        for(;*c<48;++c) *c=='-'?f=1:0;
        for(;*c>47;++c) a=10*a+(*c^48);
        S=++c;f?a=-a:0;
    #else
        reg char c=getchar(),f=0;a=0;
        for(;c<48;c=getchar()) c=='-'?f=1:0;
        for(;c>47;c=getchar()) a=10*a+(c^48);
        f?a=-a:0;
    #endif
    }
    template<class T>inline T fr() {T a;fr(a);return a;}
    #define R() fr<int>()
    inline void Putc(reg char c) {*++A=c;}
    template<class T>inline void fw(reg T x) {
        static char C[20];static int f;
        x<0?*++A='-',x=-x:0;
        while(C[++f]=48+x%10,x/=10);
        while(*++A=C[f],--f);
        // *++A=' ';
    }
    inline int flush() {fwrite(D,1,A-D,stdout);return 0;}
}
using namespace FastIO;

map<int,int>h;
template<class T>struct queue {
    int head,tail;T a[200010];
    queue() {head=tail=200005;}
    void pop() {tail--;}
    void push(T num) {a[head]=num;head--;}
    int size() {return tail-head;}
    T back() {return a[tail];}
    T front() {return a[head+1];}
    void out() {
        fw(size()),Putc('\n');
        for(int i=head+1;i<=tail;i++) fw(a[i]),Putc(' ');
    }
};
queue<int>q;

int main() {
    int n=R(),k=R();
    for(int i=1;i<=n;i++) {
        int x=R();
        if(h[x])continue;
        h[x]=1,q.push(x);
        if(q.size()>k)h[q.back()]=0,q.pop();
    }
    return q.out(),flush();
}
//Naive_Cat