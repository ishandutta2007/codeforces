#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <map>

using namespace std;
#define PB push_back
#define MP make_pair
#define eps 1e-8
#define mo 1000000007
struct point{
    double x,y;
    point(double x=0.,double y=0.):x(x),y(y){}
    point operator+(point b){return point(x+b.x,y+b.y);}
    point operator-(point b){return point(x-b.x,y-b.y);}
    point operator*(double t){return point(x*t,y*t);}
    point operator/(double t){return point(x/t,y/t);}
    double dis(){return x*x+y*y;}
    double dist(){return sqrt(dis());}
    void get(){scanf("%lf%lf",&x,&y);}
    void show(){printf("%.3f %.3f\n",x,y);}
};
double det(point a,point b){return a.x*b.y-a.y*b.x;}
double dot(point a,point b){return a.x*b.x+a.y*b.y;}

int c[1100][1100];
int n,m,k;

int getc(int n,int m){
    if (m>n) return 0;
    return c[n][m];
}

int main(){
    for (int i=0;i<1100;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
    }
    cin>>n>>m>>k;
    cout<<getc(n-1,k+k)*(long long)getc(m-1,k+k)%mo<<endl;
}