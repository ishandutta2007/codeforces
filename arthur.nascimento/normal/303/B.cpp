#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;}

main(){
       int n,m,x,y,a,b;
       scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
       
       int k = gcd(a,b);
       
       a /= k;
       b /= k;
       
       int s = min(n/a,m/b);
       
       a*=s;
       b*=s;
       
       int xi = x - (a+1)/2;
       int xf = xi + a;
       
       int yi = y - (b+1)/2;
       int yf = yi + b;
       
       int dx = 0;
       if(xi < 0)dx = -xi;
       if(xf > n)dx = n - xf;
       
       int dy = 0;
       if(yi < 0)dy = -yi;
       if(yf > m)dy = m - yf;
       
       printf("%d %d %d %d\n",xi+dx,yi+dy,xf+dx,yf+dy);

       }