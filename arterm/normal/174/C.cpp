#include <iostream>
#include <algorithm>
#include <set>

#define N 100100
#define mp make_pair
#define f first
#define s second

using namespace std;

set<pair<long,long> > s;
long n,m=0,l[N],r[N],a[N],d[N],rank[N];
pair<long, long> ans[N];

long find_(long i){
    if (d[i]==i)
    return i;
    else
    return d[i]=find_(d[i]);
}

void union_(long a, long b){
    a=find_(a);
    b=find_(b);
    if (rank[a]<rank[b])
    swap(a,b);
    d[b]=a;
    rank[a]++;
    l[a]=min(l[a],l[b]);
    r[a]=max(r[a],r[b]);
}


void read(void){
    cin>>n;
    a[0]=-1;
    d[0]=0;
    d[n+1]=n+1;
    a[n+1]=-1;
    for (long i=1; i<=n; ++i){
        cin>>a[i];
        d[i]=i;
        rank[i]=0;
        l[i]=i;
        r[i]=i;
    }

    for (long i=1; i<=n; ++i)
    if (a[i]==a[i+1])
    union_(i,i+1);

    for (long i=1; i<=n; ++i)
    if (a[i]!=a[i-1])
    s.insert(mp(-1*a[i],find_(i)));
}

void doit(void){
    pair<long, long> top;
    long h,le,ri;
    while (!s.empty()){
        top=*s.begin();
        s.erase(top);
        h=top.s;
        h=find_(h);
        le=find_(l[h]-1);
        ri=find_(r[h]+1);
        if (le==0 && ri==n+1 && a[h]==0)
        break;
        if (a[le]>a[ri]){
            for (; a[h]>a[le] && a[h]>0; --a[h])
            ans[m++]=mp(l[h],r[h]);
            union_(h,le);
        }
        else{
            for (; a[h]>a[ri] && a[h]>0; --a[h])
            ans[m++]=mp(l[h],r[h]);
            union_(h,ri);
        }

    }
    cout<<m<<"\n";
    for (long i=0; i<m; ++i)
    cout<<ans[i].f<<" "<<ans[i].s<<"\n";
}

int main()
{
    read();
    doit();

    return 0;
}