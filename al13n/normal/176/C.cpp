#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

inline int mymax(int a,int b){
	return a<b?b:a;
}
inline int mymin(int a,int b){
	return a>b?b:a;
}
inline lng mymax(lng a,lng b){
	return a<b?b:a;
}
inline lng mymin(lng a,lng b){
	return a>b?b:a;
}

struct state{
	int glue;
	int a,b;
	bool sec;
	state inv(){
		state s;
		s.glue=0;
		s.a=a;
		s.b=b;
		s.sec=sec;
		forn(i,5){
			forn(j,5){
				if(glue&(1<<((a-i)*5+(b-j))))
					s.glue|=1<<(i*5+j);
			}
		}
		return s;
	}
	bool glud(){
		return !!(glue&(1<<(a*5+b)));
	}
	bool operator<(const state &s)const{
		return mp(mp(glue,sec),mp(a,b))<mp(mp(s.glue,s.sec),mp(s.a,s.b));
	}
};

map<state,bool> mem;

vector<state> go(state s){
	vector<state> res;
	if (s.sec){
		state sss=s;
		sss.sec^=1;
		res.pb(sss);
		forn(i,s.a+1){
			forn(j,s.b+1){
				if(!i&&!j||i==s.a&&j==s.b)
					continue;
				state ss=s;
				ss.glue|=1<<(i*5+j);
				ss.sec^=1;
				res.pb(ss);
			}
		}
	}else{
		if(s.a){
			state ss=s;
			if(!ss.glud()){
				--ss.a;
				ss.sec^=1;
				res.pb(ss);
			}
			ss=s.inv();
			if(!ss.glud()){
				--ss.a;
				ss.sec^=1;
				res.pb(ss);
			}
		}
		if(s.b){
			state ss=s;
			if(!ss.glud()){
				--ss.b;
				ss.sec^=1;
				res.pb(ss);
			}
			ss=s.inv();
			if(!ss.glud()){
				--ss.b;
				ss.sec^=1;
				res.pb(ss);
			}
		}
	}
	return res;
}

bool doit(state s){
	if(mem.count(s))
		return mem[s];
	if(!s.a&&!s.b)
		return mem[s]=!s.sec;
	bool r=false;
	vector<state> ss=go(s);
	forv(i,ss){
		if(!doit(ss[i])){
			r=true;
			break;
		}
	}
	return mem[s]=r;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int n,m,x1,y1,x2,y2;
	cin>>n>>m>>x1>>y1>>x2>>y2;
	int a=abs(x1-x2);
	int b=abs(y1-y2);
	if(b<a)
		swap(a,b);
	if(b>=5||a==4||a==3&&b==4)
		cout<<"Second";
	else
		cout<<"First";
	return 0;

	forn(i,5){
		forn(j,5){
			state s;
			s.a=i;
			s.b=j;
			s.sec=false;
			s.glue=0;
			cout << i << " " << j<<": "<<doit(s)<<endl;
		}
	}

    return 0;
}