//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define X    first
#define Y    second
//:
using namespace std;
int n,out;
ll x[4],y[4],r[4];
set<pair<ll,ll> >s[4];
pair<double,double> solve(double a,double b,double c){
    return mp((-b+sqrt(b*b-4.0*a*c))/(a*2.0),(-b-sqrt(b*b-4.0*a*c))/(a*2.0));
}
ll P(ll x){return x*x;}
int check(int p,int q){
    ll R=P(r[p]+r[q]),R2=P(r[p]-r[q]);
    ll L=P(x[p]-x[q])+P(y[p]-y[q]);
    if(L==R||L==R2) return 1;
    if(L>R||L<R2) return 0;
    return 2;
}
int check2(int p,int q){
    ll R=P(r[p]+r[q]),R2=P(r[p]-r[q]);
    ll L=P(x[p]-x[q])+P(y[p]-y[q]);
    if(L==R) return 1;
    if(L==R2) return 2;
    if(L>R) return 3;
    if(L<R2) return 4;
    return 0;
}
void get(int p,int q){
    if(check2(p,q)==1){
        pair<ll,ll> a;
        a.X=(ll)((x[p]*1.0*r[q]*1.0+x[q]*1.0*r[p]*1.0)/(r[p]*1.0+r[q]*1.0)+0.3);
        a.Y=(ll)((y[p]*1.0*r[q]*1.0+y[q]*1.0*r[p]*1.0)/(r[p]*1.0+r[q]*1.0)+0.3);
        s[0].insert(a);
        s[p].insert(a);
        s[q].insert(a);
        return;
    }
    if(check2(p,q)==2){
        if(r[p]<r[q]) swap(p,q);
        pair<ll,ll> a;
        a.X=(ll)((x[q]*1.0*r[p]*1.0-x[p]*1.0*r[q]*1.0)/(r[p]*1.0-r[q]*1.0)+0.3);
        a.Y=(ll)((y[q]*1.0*r[p]*1.0-y[p]*1.0*r[q]*1.0)/(r[p]*1.0-r[q]*1.0)+0.3);
        s[0].insert(a);
        s[p].insert(a);
        s[q].insert(a);
        return;
    }
    bool flag=0;
    if(x[p]==x[q])swap(x[p],y[p]),swap(x[q],y[q]),flag=1;
    double A=P(r[p])*1.0-P(x[p])*1.0-P(y[p])*1.0;
    double B=P(r[q])*1.0-P(x[q])*1.0-P(y[q])*1.0;
    double C=((A-B)/2.0)/(x[q]*1.0-x[p]*1.0);
    double D=(y[q]*1.0-y[p]*1.0)/(x[q]*1.0-x[p]*1.0);
    pair<double,double> res=solve(D*D+1.0,2.0*D*x[p]-2.0*C*D-2.0*y[p],C*C-2.0*x[p]*C-A);
    pair<double,double> res2=mp(C-D*res.X,C-D*res.Y);
    if(flag)swap(res,res2);
    pair<ll,ll> a,b;
    a=mp((ll)(res2.X+0.3),(ll)(res.X+0.3));
    b=mp((ll)(res2.Y+0.3),(ll)(res.Y+0.3));
    s[0].insert(a),s[0].insert(b);
    s[p].insert(a),s[p].insert(b);
    s[q].insert(a),s[q].insert(b);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d%I64d%I64d",x+i,y+i,r+i),x[i]*=10000000,y[i]*=10000000,r[i]*=10000000;
    if(n==1){
        puts("2");
        return 0;
    }
    if(n==2){
        if(check(1,2)==2)puts("4");
        else puts("3");
        return 0;
    }
    if(check(1,2)+check(1,3)+check(2,3)==0){
        puts("4");
        return 0;
    }
    if(check(1,2)+check(1,3)==0){
        if(check(2,3)==2)puts("5");
        else puts("4");
        return 0;
    }
    if(check(2,1)+check(2,3)==0){
        if(check(1,3)==2)puts("5");
        else puts("4");
        return 0;
    }
    if(check(3,1)+check(3,2)==0){
        if(check(1,2)==2)puts("5");
        else puts("4");
        return 0;
    }
    if(check(1,2)==0||check(1,3)==0||check(2,3)==0){
        out=4;
        if(check(1,2)==2)out++;
        if(check(1,3)==2)out++;
        if(check(2,3)==2)out++;
        printf("%d\n",out);
        return 0;
    }
    if(check(1,2)+check(1,3)+check(2,3)==5){
        get(1,2),get(1,3),get(2,3);
        if(s[0].size()==3)puts("6");
        else puts("7");
        return 0;
    }
    get(1,2),get(1,3),get(2,3);
    printf("%d\n",s[1].size()+s[2].size()+s[3].size()+2-s[0].size());
  //	system("pause");
	return 0;
}