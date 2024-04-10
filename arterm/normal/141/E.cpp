#include <iostream>
#include <vector>

#define M 100100
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

long n,m, w[M],g[M],wc=0, ins[M], ind[M];
vector< pair<long,long> > s,d;
vector<long> ans;

void ini(void){
    for (long i=0; i<M; ++i){
        w[i]=i;
        g[i]=i;
    }
}

long get_w(long x){
    if (w[x]==x)
    return x;
    return w[x]=get_w(w[x]);
}

void uni_w(long x, long y){
    y=get_w(y);
    x=get_w(x);
    w[x]=y;
}

long get_g(long x){
    if (g[x]==x)
    return x;
    return g[x]=get_g(g[x]);
}

void uni_g(long x, long y){
    y=get_g(y);
    x=get_g(x);
    g[x]=y;
}

void read(void){
    char ch;
    cin>>n>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b>>ch;
        if (ch=='S'){
            s.pb(mp(a,b));
            uni_w(a,b);
            ins[s.size()-1]=i+1;
        }
        else{
            d.pb(mp(a,b));
            ind[d.size()-1]=i+1;
        }
    }

    for (long i=1; i<=n; ++i)
    if (w[i]==i)
    wc++;


}

int main()
{
    long wh=0,bl=0,t;
    ini();
    read();

    t=n/2;

    if (n%2==0 || wc-1>t){
        cout<<-1;
        return 0;
    }

    if (s.size()<t || d.size()<t){
        cout<<-1;
        return 0;
    }


    for (long i=0,a,b; i<d.size(); ++i){
        a=d[i].f;
        b=d[i].s;
        if (get_w(a)!=get_w(b))
        if (get_g(a)!=get_g(b)){
            ans.pb(ind[i]);
            uni_w(a,b);
            uni_g(a,b);
            wc--;
            bl++;
        }
    }

    if (wc!=1){
        cout<<-1;
        return 0;
    }

    for (long i=0,a,b; bl<t && i<d.size(); ++i){
        a=d[i].f;
        b=d[i].s;
        if (get_g(a)!=get_g(b)){
            ans.pb(ind[i]);
            uni_g(a,b);
            bl++;
        }
    }



    for (long i=0,a,b; wh<t && i<s.size(); ++i){
        a=s[i].f;
        b=s[i].s;
        if (get_g(a)!=get_g(b)){
            ans.pb(ins[i]);
            uni_g(a,b);
            wh++;
        }
    }

    if (bl<t || wh<t){
        cout<<-1;
        return 0;
    }

    cout<<n-1<<"\n";
    for (long i=0; i+1<n; ++i)
    cout<<ans[i]<<" ";

    return 0;
}