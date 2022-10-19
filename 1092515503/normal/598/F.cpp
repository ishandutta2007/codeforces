#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps=1e-6;
int cmp(double x){
	if(x>eps)return 1;
	if(x<-eps)return -1;
	return 0;
}
struct Vector{
	double x,y;
	Vector(){}
	Vector(double X,double Y){x=X,y=Y;}
	friend Vector operator +(const Vector &u,const Vector &v){return Vector(u.x+v.x,u.y+v.y);}
	friend Vector operator -(const Vector &u,const Vector &v){return Vector(u.x-v.x,u.y-v.y);}
	friend Vector operator *(const Vector &u,const double &v){return Vector(u.x*v,u.y*v);}
	friend Vector operator /(const Vector &u,const double &v){return Vector(u.x/v,u.y/v);}
	friend double operator &(const Vector &u,const Vector &v){return u.x*v.y-u.y*v.x;}//cross times
	friend double operator |(const Vector &u,const Vector &v){return u.x*v.x+u.y*v.y;}//point times
	double operator ~()const{return sqrt(x*x+y*y);}//the modulo of a vector
	double operator !()const{return atan2(y,x);}//the angle of a vector
	friend bool operator <(const Vector &u,const Vector &v){return cmp(u.x-v.x)?u.x<v.x:u.y<v.y;}
	friend bool operator ==(const Vector &u,const Vector &v){return !cmp(u.x-v.x)&&!cmp(u.y-v.y);}
	void read(){scanf("%Lf%Lf",&x,&y);}
	void print()const{printf("(%Lf,%Lf)",x,y);}
}p[1010];
Vector read(){Vector x;x.read();return x;}
typedef Vector Point;
struct Line{
	Point x,y;
	Vector z;
	Line(){}
	Line(Point X,Point Y){x=X,y=Y,z=Y-X;}
	void print()const{x.print(),y.print();}
	friend Point operator &(const Line &u,const Line &v){return u.x+u.z*((v.z&(u.x-v.x))/(u.z&v.z));}
	friend int operator &(const Line &u,const Point &v){return cmp((v-u.x)&(v-u.y));}//point v is on which side of line u
};
typedef Line Segment;
int n,m;
vector<Segment>u;
vector<Point>v,w;
vector<int>b;
bool on[1010];
double calc(Line l){
	u.clear(),v.clear(),memset(on,false,sizeof(on));
	for(int i=0;i<n;i++){
		if(!cmp((p[i]-p[(i+1)%n])&l.z)){//two lines parallel
			if(cmp(l.z&(p[i]-l.x)))continue;
			u.emplace_back(p[i],p[(i+1)%n]);//two lines coincide
			Segment tmp(p[i],p[(i+1)%n]);if((tmp&p[(i+n-1)%n])!=(tmp&p[(i+2)%n]))v.push_back(p[i]);
			//the line crossed the border at the coincided edge
			continue;
		}
		Point x=Line(p[i],p[(i+1)%n])&l;//if not parallel, this is the intersection point
		if(x==p[i]){on[i]=true;continue;}
		if(x==p[(i+1)%n]){on[(i+1)%n]=true;continue;}//if intersection point is concide with one endpoint of the segment,consider it specially
		if(cmp((x-p[i])|(x-p[(i+1)%n]))==1)continue;//intersection is not on the segment
		v.push_back(x);
	}
	for(int i=0;i<n;i++){//this loop only consider points exactly on the line
		if(!on[i])continue;
		if(on[(i+n-1)%n]||on[(i+1)%n])continue;//if this point is endpoint of a coinciding edge, do not bother as we've considered it previously
		Point x=(l.x==p[i]?l.y:l.x);//find one point on the line which do not coincide with the current point
		Segment A(p[(i+n-1)%n],p[i]);bool a=((A&x)!=(A&p[(i+1)%n]));
		Segment B(p[(i+1)%n],p[i]);bool b=((B&x)!=(B&p[(i+n-1)%n]));
		if(a==b)v.push_back(p[i]);//cross the border.
	}
	sort(v.begin(),v.end()),w=v;
	for(auto i:u)w.push_back(i.x),w.push_back(i.y);
	sort(w.begin(),w.end());
	b.assign(w.size(),0);
	for(int i=0;i<v.size();i+=2){
		int l=lower_bound(w.begin(),w.end(),v[i])-w.begin();
		int r=lower_bound(w.begin(),w.end(),v[i+1])-w.begin();
		b[l]++,b[r]--;
	}
	for(int i=0;i<u.size();i++){
		int l=lower_bound(w.begin(),w.end(),u[i].x)-w.begin();
		int r=lower_bound(w.begin(),w.end(),u[i].y)-w.begin();
		if(l>r)swap(l,r);
		b[l]++,b[r]--;
	}
	for(int i=1;i<b.size();i++)b[i]+=b[i-1];
	double ret=0;
	for(int i=0;i+1<b.size();i++)if(b[i])ret+=~(w[i+1]-w[i]);
	return ret;
}
int N;
int main(){
	scanf("%d%d",&N,&m);
	for(int i=0;i<N;i++){
		p[n].read();
		if(n>=2&&cmp((p[n]-p[n-1])&(p[n]-p[n-2]))==0)n--,p[n]=p[n+1];//eliminating those 180-degree angles.
		n++;
	}
	if(n>=3&&cmp((p[0]-p[n-1])&(p[0]-p[n-2]))==0)n--;
	if(n>=3&&cmp((p[1]-p[0])&(p[1]-p[n-1]))==0){for(int i=0;i+1<n;i++)p[i]=p[i+1];n--;}
	while(m--)printf("%.10Lf\n",calc(Line(read(),read())));
	return 0;
}
/*
12 5
-1 0
-2 1
-1 2
0 1
1 2
2 1
1 0
2 -1
1 -2
0 -1
-1 -2
-2 -1
-2 -1 -1 0
-2.01 -1 -1.01 0
-1.99 -1 -0.99 0
-1 0 1 0
1 2 2 1

8 4
0 0
0 1
0 2
1 2
2 2
2 1
1 1
1 0
1 0 1 1
0 1 1 1
0 0 1 1
1 0 2 1

3 3
100000 100000
-99999.99 -100000
-100000 -100000
100000 100000 -99999.99 -100000
-99999.99 -100000 -100000 -100000
-100000 -100000 -100000 -99999.99
*/