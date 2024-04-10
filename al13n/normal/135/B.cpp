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

vec src[8];

bool rect(vec *v){
	forn(i,4)
		if((v[(i+1)%4]-v[i]).dot(v[(i+2)%4]-v[(i+1)%4])||(v[(i+1)%4]-v[i]).dot((v[(i+2)%4]-v[(i+1)%4]).perp())<0)
			return false;
	return true;
}

bool square(vec *v){
	if(!rect(v))
		return false;
	if((v[0]-v[1]).dot(v[0]-v[1])!=(v[1]-v[2]).dot(v[1]-v[2]))
		return false;
	return true;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	forn(i,8)
		src[i].read(i+1);

	do{
		if(square(src)&&rect(src+4)){
			cout<<"YES";
			forn(i,8){
				if(i%4==0)
					cout<<endl;
				cout<<src[i].id<<' ';
			}
			exit(0);
		}
	}while(next_permutation(src,src+8));

	cout<<"NO";

	return 0;
}