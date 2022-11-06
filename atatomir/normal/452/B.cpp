#include <iostream>
#include <cmath>

#define write(a,b) cout<<(a)<<' '<<(b)<<'\n';

using namespace std;

long n,m;
double s1,s2,d1,d2,sol;

inline double sqr(double x){ return x * x;}

int main()
{
    cin >> n >> m;

    if(n==0){
        write(0,1);
        write(0,m);
        write(0,0);
        write(0,m-1);
    } else
    if(m==0){
        write(1,0);
        write(n,0);
        write(0,0);
        write(n-1,0);
    } else {
        s1 = sqrt(sqr(n)+sqr(m)) + 2*(sqrt(sqr(n)+sqr(m-1)));
        s2 = sqrt(sqr(n)+sqr(m)) + 2*(sqrt(sqr(n-1)+sqr(m)));
        d1 = 2* sqrt(sqr(n)+sqr(m)) + n;
        d2 = 2* sqrt(sqr(n)+sqr(m)) + m;
        sol = max(max(s1,s2),max(d1,d2));
        if(sol == s1){
            write(n,m-1);
            write(0,0);
            write(n,m);
            write(0,1);
        } else
        if(sol == s2){
            write(n-1,m);
            write(0,0);
            write(n,m);
            write(1,0);
        } else
        if(sol == d1){
            write(0,0);
            write(n,m);
            write(0,m);
            write(n,0);
        } else
        if(sol == d2){
            write(0,0);
            write(n,m);
            write(n,0);
            write(0,m);
        }
    }
    return 0;
}