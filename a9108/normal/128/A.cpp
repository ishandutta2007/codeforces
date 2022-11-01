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

char s[20][20];
bool f[100][20][20];
bool check(int t,int i,int j){
	i-=t;
	if (i<0) return false;
	if (s[i][j]=='S') return true;
	return false;
}
void relax(int t,int i,int j){
	if (i<0||i>7||j<0||j>7) return;
	if (check(t-1,i,j)||check(t,i,j)) return;
	f[t][i][j]=true;
}

int main(){
	for (int i=0;i<8;i++) scanf("%s",s[i]);
	memset(f,false,sizeof(f));
	f[0][7][0]=true;
	bool ans=false;
	for (int t=0;t<50;t++){
		if (f[t][0][7]) ans=true;
		for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
		if (f[t][i][j]){
			for (int dx=-1;dx<=1;dx++)
			for (int dy=-1;dy<=1;dy++) relax(t+1,i+dx,j+dy);
		}
	}
	if (ans) printf("WIN\n");
	else printf("LOSE\n");
}