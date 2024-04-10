#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
double alpha;
inline pair<double,double> translate(pair<double,double> x)
{
	double a=x.first;
	double b=x.second;
	double cosa=cos(alpha);
	double sina=sin(alpha);
	return make_pair(a*cosa-b*sina,b*cosa+a*sina);
}
inline double area(pair<double,double>a,pair<double,double>b)
{
	return (a.first*b.second-a.second*b.first)/2.;
}
pair<double,double> pivot;
inline bool comp(pair<double,double> a, pair<double,double> b)
{
	auto aa=make_pair(a.first-pivot.first,a.second-pivot.second);
	auto bb=make_pair(b.first-pivot.first,b.second-pivot.second);
	return area(aa,bb)<0;
}
int main()
{
	int w,h,a;
	scanf("%d%d%d",&w,&h,&a);
	if(a==0 || a==180)
	{
		printf("%lld",1LL*w*h);
		return 0;
	}
	if(a==90)
	{
		printf("%lld",1LL*min(w,h)*min(w,h));
		return 0;
	}
	alpha=a*3.14159265358979/180;
	auto A=make_pair(w/2.,h/2.);
	auto B=make_pair(-w/2.,h/2.);
	auto C=make_pair(-w/2.,-h/2.);
	auto D=make_pair(w/2.,-h/2.);
	pair<double,double> t[5];
	t[0]=translate(A);
	t[1]=translate(B);
	t[2]=translate(C);
	t[3]=translate(D);
	t[4]=translate(A);
#define x first
#define y second
	vector<pair<double,double> > V;
	for(int i=0;i<4;i++)
	{
		auto A=t[i],B=t[i+1];
		if(
		(A.x < w/2. && w/2. < B.x) ||
		(B.x < w/2. && w/2. < A.x)
		)
		{
			double y=(A.y*(B.x-w/2.)+B.y*(w/2.-A.x))/(B.x-A.x);
			if(-h/2. <y && y<h/2.) V.emplace_back(w/2.,y);
		}
		if(
		(A.x < -w/2. && -w/2. < B.x) ||
		(B.x < -w/2. && -w/2. < A.x)
		)
		{
			double y=(A.y*(B.x+w/2.)+B.y*(-w/2.-A.x))/(B.x-A.x);
			if(-h/2. <y && y<h/2.) V.emplace_back(-w/2.,y);
		}
		if(
		(A.y < h/2. && h/2. < B.y) ||
		(B.y < h/2. && h/2. < A.y)
		)
		{
			double x=(A.x*(B.y-h/2.)+B.x*(h/2.-A.y))/(B.y-A.y);
			if(-w/2. <x && x<w/2.) V.emplace_back(x,h/2.);
		} 
		if(
		(A.y < -h/2. && -h/2. < B.y) ||
		(B.y < -h/2. && -h/2. < A.y)
		)
		{
			double x=(A.x*(B.y+h/2.)+B.x*(-h/2.-A.y))/(B.y-A.y);
			if(-w/2. <x && x<w/2.) V.emplace_back(x,-h/2.);
		} 
	}
	for(int i=1;i<V.size();i++)
		if(V[0]>V[i]) swap(V[0],V[i]);
	pivot=V[0];
	auto it=V.begin();
	it++;
	sort(it,V.end(),comp);
	double ans=0;
	for(int i=0;i<V.size();i++)
	{
		//printf("%.12lf %.12lf\n",V[i].x,V[i].y);
		//fprintf(stderr,"%.12lf\n",area(V[i],V[(i+1)%V.size()]));
		ans+=area(V[i],V[(i+1)%V.size()]);
	}
	printf("%.12lf",abs(ans));
}