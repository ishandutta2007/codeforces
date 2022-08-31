#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()

struct vec{
	int x,y;
	int id;
	vec(){}
	vec(int x,int y):x(x),y(y){}
	int dot(vec b){
		return x*b.x+y*b.y;
	}
	vec perp(){
		return vec(-y,x);
	}
	void read(int i){
		cin>>x>>y;
		id=i;
	}
	vec operator-(vec b){
		return vec(x-b.x,y-b.y);
	}
	bool operator<(vec b)const{
		return id<b.id;
	}
};

char src[1000000];
bool res[4];
int n;

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	gets(src);
	n=strlen(src);
	int c0=0,c1=0;
	forn(i,n)
	if(src[i]=='0')
		++c0;
	else if(src[i]=='1')
		++c1;
	int cc=n-c0-c1;
	int a=(n+1)/2-1;
	int b=n/2-1;
	res[0]=c1<=a;
	res[3]=c0<=b;
	if(c1+cc>a&&c0+cc>b){
		if(src[n-1]=='0')
			res[2]=true;
		else if(src[n-1]=='1')
			res[1]=true;
		else{
			if(c0+cc-1>b)
				res[1]=true;
			if(c1+cc-1>a)
				res[2]=true;
		}
	}
	forn(i,4)
		if(res[i])
			cout<<i/2<<i%2<<endl;

	return 0;
}