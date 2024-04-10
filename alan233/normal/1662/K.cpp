// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const double eps=1e-10;
const double MAGIC=0.9;

struct Point{
    double x,y;
    Point (double _x=0,double _y=0){
        x=_x,y=_y;
    }
    double norm(){
        return sqrt(x*x+y*y);
    }
}a,b,c;
Point operator + (const Point &a,const Point &b){
    return Point(a.x+b.x,a.y+b.y);
}
Point operator - (const Point &a,const Point &b){
    return Point(a.x-b.x,a.y-b.y);
}
Point operator * (const Point &a,const double &b){
    return Point(a.x*b,a.y*b);
}
Point operator / (const Point &a,const double &b){
    return Point(a.x/b,a.y/b);
}
double dist(const Point &a,const Point &b){
    return (a-b).norm();
}
double calc(Point a,Point b,Point c){
    double t=dist(a,b)+dist(b,c)+dist(a,c);
    Point ans=a;
    while(t>eps){
        Point d;
        for(auto p:{a,b,c}){
            if(dist(p,ans)>eps)
                d=d+(p-ans)/dist(p,ans);
        }
        ans=ans+d*t,t*=MAGIC;
    }
    return dist(a,ans)+dist(b,ans)+dist(c,ans);
}

int main(){
    scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    Point ans=a;double t=5,ANS=2e9;
    while(t>eps){
        vector<double> f={calc(ans,a,b),calc(ans,b,c),calc(ans,a,c)};
        ckmin(ANS,max({f[0],f[1],f[2]}));
        int pos=min_element(f.begin(),f.end())-f.begin();
        if(pos==0){
            ans=ans+(c-ans)*t;
        }else if(pos==1){
            ans=ans+(a-ans)*t;
        }else{
            ans=ans+(b-ans)*t;
        }
        t*=MAGIC;
    }
    printf("%.10f\n",ANS);
    return 0;
}