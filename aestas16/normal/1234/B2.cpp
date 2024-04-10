#include <cstdio>
#include <map>

#define reg register

using std::map;

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

map<int,int>h;
template<class T>struct queue
{
    int head,tail;
    T a[200010];
    queue() {head=tail=200005;}
    void pop() {tail--;}
    void push(T num) {a[head]=num;head--;}
    int size() {return tail-head;}
    T back() {return a[tail];}
    T front() {return a[head+1];}
    bool empty() {if(head==tail)return true;return false;}
    void out() {
        printf("%d\n",size());
        for(int i=head+1;i<=tail;i++) printf("%d ",a[i]);
        puts("");
    }
};
queue<int>q;

int main() {
    int n=R(),k=R();
    for(int i=1;i<=n;i++) {
        int x=R();
        if(h[x])continue;
        h[x]=1;q.push(x);
        if(q.size()>k) {
            h[q.back()]=0;
            q.pop();
        }
    }
    q.out();
    return 0;
}
//Naive_Cat