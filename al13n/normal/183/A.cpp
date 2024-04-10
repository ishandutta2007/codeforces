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



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	lng c[1<<4]={0};
	int n;
	cin>>n;
	static char line[10];
	gets(line);
	forn(i,n){
		int t=0;
		gets(line);
		for(int j=0;line[j];++j){
			int c=line[j];
			int v;
			if(c=='U')
				v=0;
			else if(c=='D')
				v=1;
			else if(c=='L')
				v=2;
			else if(c=='R')
				v=3;
			else
				exit(123);
			t|=1<<v;
		}
		++c[t];
	}

	cout<<(c[5]+c[10]+c[15]+1)*(c[9]+c[6]+c[15]+1);

	return 0;
}