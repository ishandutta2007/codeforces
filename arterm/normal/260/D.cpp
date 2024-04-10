#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define M 100100
#define f first
#define s second
#define mp make_pair

using namespace std;

set<pair<long,long> > g[2];
long n,p[M];


void read(void){
    cin>>n;
    for (long c,s,i=1; i<=n; ++i){
        cin>>c>>s;
        p[i]=i;
        g[c].insert(mp(s,i));
    }
}

long get(long x){
    if (p[x]==x)
    return x;
    return p[x]=get(p[x]);
}

void uni(long x, long y){
    x=get(x);
    y=get(y);
    p[y]=x;
}

void kill(void){
    set<pair<long,long> > ::iterator it,d;
    pair<long,long> h;
    long w;
    for (long i=1; i<n; ++i)
        if (g[0].begin()->f < g[1].begin()->f){
            d=g[0].begin();
            it=g[1].end();
            it--;
            while (get(d->s)==get(it->s))
            it--;

            uni(d->s,it->s);

            w=d->f;

            cout<<d->s<<" ";

            cout<<it->s<<" ";
            cout<<w<<"\n";
            if (g[0].size()>1)
            g[0].erase(*d);
            h=mp(it->f-w,it->s);
            if (g[1].size()>1)
            g[1].erase(*it);
            g[1].insert(h);
        }
        else{
            d=g[1].begin();
            it=g[0].end();
            it--;

            while (get(d->s)==get(it->s))
            it--;

            uni(d->s,it->s);


            w=d->f;

            cout<<d->s<<" ";

            cout<<it->s<<" ";
            cout<<w<<"\n";

            if (g[1].size()>1)
            g[1].erase(*d);
            h=mp(it->f-w,it->s);
            if (g[0].size()>1)
            g[0].erase(*it);
            g[0].insert(h);
        }
}

int main()
{
    read();
    kill();
    return 0;
}