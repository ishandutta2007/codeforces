#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double t=0;
const double eps=1e-9;

struct line
{
    ll a,b,c;
    double l,r;
    line(ll x,ll y,ll dx,ll dy,double nl,double nr)
    {
        a=-dy;
        b=dx;
        c=-a*x-b*y;
        ll g=gcd(gcd(a,b),c);
        if(a<0) g=-g;
        a/=g; b/=g; c/=g;
        l=nl;
        r=nr;
    }
    bool operator<(const line &o)const{return ((-a*t-c)/b<(-o.a*t-o.c)/o.b);}
    friend bool intersect(line p,line q)
    {
        if(p.a==q.a&&p.b==q.b&&p.c==q.c) return (max(p.l,q.l)-eps<=min(p.r,q.r));
        if(p.a*q.b-p.b*q.a==0) return 0;
        double x=double(p.b*q.c-q.b*p.c)/(p.a*q.b-q.a*p.b);
        return (max(p.l,q.l)-eps<=x&&x<=eps+min(p.r,q.r));
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,5>> a(n);
    for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin >> a[i][j];
    auto go=[&](double u)->bool
    {
        vector<line> v;
        vector<tuple<double,int,int>> e;
        for(int i=0;i<n;i++)
        {
            auto [x,y,dx,dy,k]=a[i];
            double l=x;
            double r=x+(double(dx)/hypot(dx,dy))*k*u;
            if(dx<0) swap(l,r);
            v.push_back(line(x,y,dx,dy,l,r));
            e.push_back({l,i,0});
            e.push_back({r,i,1});
        }
        ranges::sort(e);
        vector<multiset<line>::iterator> it(n);
        multiset<line> s;
        for(auto [x,i,tp]:e)
        {
            t=x;
            if(tp==0)
            {
                it[i]=s.insert(v[i]);
                if(it[i]!=s.begin()&&intersect(*it[i],*prev(it[i]))) return 1;
                if(next(it[i])!=s.end()&&intersect(*it[i],*next(it[i]))) return 1;
            }
            else
            {
                if(it[i]!=s.begin()&&next(it[i])!=s.end()&&intersect(*prev(it[i]),*next(it[i]))) return 1;
                s.erase(it[i]);
            }
        }
        return 0;
    };
    double l=0,r=1e10;
    for(int e=0;e<100;e++)
    {
        double m=(l+r)/2;
        if(go(m)) r=m;
        else l=m;
    }
    if(go(r)) cout << fixed << setprecision(15) << r << "\n";
    else cout << "No show :(\n";
    return 0;
}