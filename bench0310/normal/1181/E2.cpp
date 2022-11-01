#include <bits/stdc++.h>

using namespace std;

struct obj
{
    int a,b,c,d;
};

bool cmpl(obj a,obj b) {return make_pair(a.a,a.b)<make_pair(b.a,b.b);}
bool cmpr(obj a,obj b) {return make_pair(a.c,a.d)>make_pair(b.c,b.d);}
bool cmpd(obj a,obj b) {return make_pair(a.b,a.a)<make_pair(b.b,b.a);}
bool cmpu(obj a,obj b) {return make_pair(a.d,a.c)>make_pair(b.d,b.c);}

bool solve(auto &l,auto &r,auto &d,auto &u)
{
    int n=l.size();
    auto clean=[&](auto &src,int cnt)->bool
    {
        set<obj,decltype(&cmpl)> ll(&cmpl),rr(&cmpr),dd(&cmpd),uu(&cmpu);
        while(cnt--)
        {
            obj t=*src.begin();
            l.erase(t); r.erase(t); d.erase(t); u.erase(t);
            ll.insert(t); rr.insert(t); dd.insert(t); uu.insert(t);
        }
        return solve(ll,rr,dd,uu);
    };
    auto split=[&]()->bool
    {
        auto li=l.begin();
        auto ri=r.begin();
        auto di=d.begin();
        auto ui=u.begin();
        int lnow=li->c;
        int rnow=ri->a;
        int dnow=di->d;
        int unow=ui->b;
        for(int i=0;i<n;i++)
        {
            if(lnow<=(li->a)) return clean(l,i);
            if(rnow>=(ri->c)) return clean(r,i);
            if(dnow<=(di->b)) return clean(d,i);
            if(unow>=(ui->d)) return clean(u,i);
            lnow=max(lnow,li->c);
            rnow=min(rnow,ri->a);
            dnow=max(dnow,di->d);
            unow=min(unow,ui->b);
            li++; ri++; di++; ui++;
        }
        return 0;
    };
    while(n>1)
    {
        if(split()==0) return 0;
        n=l.size();
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    set<obj,decltype(&cmpl)> l(&cmpl),r(&cmpr),d(&cmpd),u(&cmpu);
    for(int i=0;i<n;i++)
    {
        obj t;
        scanf("%d%d%d%d",&t.a,&t.b,&t.c,&t.d);
        l.insert(t); r.insert(t); d.insert(t); u.insert(t);
    }
    if(solve(l,r,d,u)) printf("YES\n");
    else printf("NO\n");
    return 0;
}