#include <fstream>
#include <algorithm>
#include <queue>

#define M 100100
#define mp make_pair
#define f first
#define s second

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

long n,h[M],t=0,g=0,l,s=1;
pair<long,long> e[2*M],f[4*M];
bool u[M];
long q[M];

void push(long x){
    long y=s++;
    q[y]=x;
    while(y>1 && h[q[y]]>h[q[y/2]]){
        swap(q[y],q[y/2]);
        y/=2;
    }
}

long top(void){
    return q[1];
}

void pop(void){
    long y=1,n1,n2;
    q[1]=q[--s];
    while (y<s){
        n1=y;
        n2=y;
        if (2*y<s && h[q[2*y]]>h[q[y]])
        n1=2*y;
        if (2*y+1<s && h[q[2*y+1]]>h[q[y]])
        n2=2*y+1;
        if (h[q[n1]]<h[q[n2]])
        n1=n2;
        if (n1==y)
        break;
        swap(q[y],q[n1]);
        y=n1;
    }
}

void read(void){
    cin>>n;
    for (long i=1,a,l,r; i<=n; ++i){
        cin>>h[i]>>l>>r;
        e[2*i-2]=mp(l,i);
        e[2*i-1]=mp(r,i);
    }
    n*=2;
    h[0]=0;
    sort(e,e+n);
}

void make(void){
    u[0]=1;
    push(0);
    for (long i=0,j; i<n;i=j){
        //cout<<"Now we are there:"<<e[i].f;
        for (j=i; j<n && e[j].f==e[i].f;++j)
        if (u[e[j].s])
        u[e[j].s]=0;
        else{
            push(e[j].s);
            u[e[j].s]=1;
        }
        while (!u[top()])
        pop();
        //cout<<" top is "<<h[top()]<<"\n";
        if (h[top()]!=g){
            f[t++]=mp(e[i].f,g);
            g=h[top()];
            f[t++]=mp(e[i].f,g);
        }
    }
}

void write(void){
    cout<<t<<endl;
    for (long i=0;i<t; ++i)
    cout<<f[i].f<<" "<<f[i].s<<"\n";
}


int main()
{
    read();
    make();
    write();
    return 0;
}