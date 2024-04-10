#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define forv(i,v) forn(i,(v).size())
#define fors(i,s) forn(i,(v).length())
#define X first
#define Y second
#define PII pair<int,int> 
typedef long long lng;
const int iinf=1000000000;
const lng linf=1000000000000000000;
const double dinf=1e200;

struct vec {
	double x,y;

	vec(){}
	vec(double x,double y):x(x),y(y){}

	double dot(const vec &b)const{
		return x*b.x+y*b.y;
	}

	double len()const{
		return sqrt(dot(*this));
	}

	vec pp()const{
		return vec(y,-x);
	}

	vec& operator+=(const vec &b){
		x+=b.x;
		y+=b.y;
		return *this;
	}

	vec& operator-=(const vec &b){
		x-=b.x;
		y-=b.y;
		return *this;
	}

	vec& operator*=(double b){
		x*=b;
		y*=b;
		return *this;
	}

	vec& operator/=(double b){
		x/=b;
		y/=b;
		return *this;
	}

	vec operator+(const vec &b)const{
		return vec(x+b.x,y+b.y);
	}

	vec operator-(const vec &b)const{
		return vec(x-b.x,y-b.y);
	}

	vec operator*(double b)const{
		return vec(x*b,y*b);
	}

	vec operator/(double b)const{
		return vec(x/b,y/b);
	}

	vec normd()const{
		return (*this)*(1./len());
	}
};

PII src[300];
int res[1100000];

lng doit(PII a,PII b,int h){
	lng x1=a.X;
	lng y1=a.Y-h;
	lng x2=b.X;
	lng y2=b.Y-h;
	lng t=(x2-x1)*y2;
	if(y1==y2)
		return -1;
	if(t%(y1-y2))
		return -1;
	lng p=t/(y1-y2)+x2;
	return p;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;
	forn(i,n){
		res[i]=1;
	}
	forn(i,m){
		cin>>src[i].X>>src[i].Y;
	}
	forn(i,m){
		forn(j,i){
			lng p=doit(src[i],src[j],0);
			--p;
			if(p<0||p>=n)
				continue;
			int c=2;
			forn(k,j){
				lng t=doit(src[i],src[j],src[k].Y);
				if(t==src[k].X)
					++c;
			}
			if(c>res[p])
				res[p]=c;
		}
	}

	lng r=0;
	forn(i,n)
		r+=res[i];
	cout<<r;

	return 0;
}