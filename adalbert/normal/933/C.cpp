#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int x[10],y[10],r[10];

int sqr(int a)
{
    return(a*a);
}

int dist(int i, int j)
{
    return(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

bool intersect(int i, int j)
{
    return(dist(i,j)<sqr(r[i]+r[j]) && (sqrt(dist(i,j))+ld(min(r[i],r[j])))>ld(max(r[i],r[j])));
}

bool dot(int i, int j)
{
    return(dist(i,j)==sqr(r[i]+r[j]) || dist(i,j)==sqr(max(r[i],r[j])-min(r[i],r[j])));
}

vector <pair<ld,ld> > vec;
void get_line_cyrcle(ld a, ld b, ld c, ld r)
{
    //cout<<"line :: "<<a<<" "<<b<<" "<<c<<"\n";
    if (abs(a)<0.00000001)
    {
        ld Y=-c/b;
        if (Y<=r)
        {
            ld X=r*r-Y*Y;
            if (X<0)
                return;
            X=sqrt(X);
            vec.pb({X,Y});
            if (abs(X)>0.00000001) vec.pb({-X,Y});
        }
        return;
    } else
    if (abs(b)<0.000000001)
    {
        ld X=-c/a;
        if (X<=r)
        {
            ld Y=r*r-X*X;
            if (Y<0)
                return;
            Y=sqrt(Y);
            vec.pb({X,Y});
            if (abs(Y)>0.00000001) vec.pb({X,-Y});
        }
        return;
    }
    ld A=a*a+b*b;
    ld B=2*c*b;
    ld C=c*c-r*r*a*a;
    ld D=B*B-4*A*C;
    if (D<0.0) return;
    D=sqrt(D);
    ld Y=(-B+D)/2.0/A;
    ld X=(-c-Y*b)/a;
    vec.pb({X,Y});
    if (D>0.000000001)
    {
        Y=(-B-D)/2.0/A;
        X=(-c-Y*b)/a;
        vec.pb({X,Y});
    }
}
void get_cyrcle_cyrcle(ld r1, ld x2, ld y2, ld r2)
{
    ld a=-2*x2;
    ld b=-2*y2;
    ld c=x2*x2+y2*y2+r1*r1-r2*r2;
    get_line_cyrcle(a,b,c,r1);
}

ld dist2(ld x1, ld y1, ld x2, ld y2)
{
    return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

bool check(int &res)
{
    get_cyrcle_cyrcle(r[1],x[2]-x[1],y[2]-y[1],r[2]);

    for (auto i:vec)
    {
        if(abs((dist2(i.fir,i.sec,x[3]-x[1],y[3]-y[1])-r[3]))<1e-7)
            res--;

    }

    return(0);
}

signed main()
{
    int n;
    cin>>n;

    int res=0;

    cin>>x[1]>>y[1]>>r[1];

    res=2;

    if (n>=2)
    {
        res++;
        cin>>x[2]>>y[2]>>r[2];
        if (intersect(2,1))
            res++;
    }

    if (n>=3)
    {
        cin>>x[3]>>y[3]>>r[3];
        res++;
        if (!intersect(1,3) && !intersect(2,3))
        {
            if (dot(1,3) && dot(2,3) && (dot(1,2) || intersect(1,2)))
                res++;
        } else
        if (!intersect(1,3) && intersect(2,3))
        {
            if (dot(1,3) && (dot(1,2) || intersect(1,2)))
                res++;
            res++;
        } else
        if (intersect(1,3) && !intersect(2,3))
        {
            if (dot(2,3) && (dot(1,2) || intersect(1,2)))
                res++;
            res++;
        } else
        if (!intersect(1,2))
        {
            if (dot(1,2))
                res++;
            res+=2;
        } else
        {
            res+=3;

        }
        check(res);
    }
    cout<<res<<'\n';
}
/*
3
-2 -3 5
-6 1 7
5 4 5
*/