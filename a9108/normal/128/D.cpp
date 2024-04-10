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

int a[110000];
int n;
int mi,ma;

bool check1(){
    int la=a[0]-1;
    ma=a[n-1];
    mi=a[0];
    for (int i=0;i<n;i++){
        if (a[i]==la+1){
            la=a[i];
            a[i]=-1;
        }
    }
    if (la!=ma) return false;
    for (int i=n-1;i>=0;i--)
    if (a[i]==la-1&&a[i]!=mi){
        la=a[i];
        a[i]=-1;
    }
    if (la!=mi+1) return false;
    return true;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    if (!check1()) printf("NO\n");
    else {
        bool f=true;
        int la=-1,cnt=0;
        for (int i=0;i<n;i++)if (a[i]!=-1){
            if (la==-1) la=a[i],cnt=1;
            else {
                if (a[i]==la) cnt++;
                else if (a[i]==la+1) {
                    cnt--;
                    if (cnt==0) la=-1;
                }
                else {
                    f=false;
                    break;
                }
            }
        }
        if (la!=-1) f=false;
        if (f) printf("YES\n");
        else printf("NO\n");
    }
}