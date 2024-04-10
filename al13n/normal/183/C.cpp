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

int gcd(int a,int b){
	return a?gcd(b%a,a):b;
}

vector<PII> ugr[110000];
int bal[110000];
int col[110000];
bool was[110000];
int D;
int n;

void dfs1(int v,int b){
	if(was[v]){
		D=gcd(D,abs(b-bal[v]));
		return;
	}
	was[v]=true;
	bal[v]=b;
	forv(i,ugr[v]){
		int p=ugr[v][i].X;
		dfs1(p,b+ugr[v][i].Y);
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	int m;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		ugr[a].pb(mp(b,1));
		ugr[b].pb(mp(a,-1));
	}

forn(i,n)
if(!was[i])
	dfs1(i,0);

	if(!D)
		D=n;

	cout<<D;

	return 0;
}