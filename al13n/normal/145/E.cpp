#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
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

int c0[4100000];
int pp[4100000];
int ppp[4100000];
bool flip[4100000];
char src[1100000];

void pre(int a,int b,int k){
	if(!flip[k])
		return;
	c0[k]=b-a-c0[k];
	swap(pp[k],ppp[k]);
	flip[k]=false;
	if(b>a+1){
		flip[k*2+1]^=1;
		flip[k*2+2]^=1;
	}
}

void calc(int a,int b,int c,int k){
	pre(a,c,k*2+1);
	pre(c,b,k*2+2);
	c0[k]=c0[k*2+1]+c0[k*2+2];
	pp[k]=max(pp[k*2+1],2*c0[k*2+1]-(c-a)+pp[k*2+2]);
	ppp[k]=max(ppp[k*2+1],(c-a)-2*c0[k*2+1]+ppp[k*2+2]);
}

void build(int a,int b,int k){
	if(b==a+1){
		c0[k]=((src[a]=='4')?1:0);
		pp[k]=c0[k];
		ppp[k]=1-c0[k];
		return;
	}
	int c=(a+b)>>1;
	build(a,c,k*2+1);
	build(c,b,k*2+2);
	calc(a,b,c,k);
}

void flipseg(int l,int r,int a,int b,int k){
	if(l==a&&r==b){
		flip[k]^=1;
		return;
	}
	pre(a,b,k);
	int c=(a+b)>>1;
	if(r<=c)
		flipseg(l,r,a,c,k*2+1);
	else if(l>=c)
		flipseg(l,r,c,b,k*2+2);
	else{
		flipseg(l,c,a,c,k*2+1);
		flipseg(c,r,c,b,k*2+2);
	}
	calc(a,b,c,k);
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;
	scanf("\n%s",src);
	if(n!=strlen(src)){
		cerr<<"nya";
		exit(342);
	}
	build(0,n,0);
	forn(i,m){
		char cmd[15];
		scanf("\n%s",cmd);
		if(cmd[0]=='s'){
			int l,r;
			scanf("%d%d",&l,&r);
			--l;
			flipseg(l,r,0,n,0);
		}else if(cmd[0]=='c'){
			pre(0,n,0);
			printf("%d\n",pp[0]+n-c0[0]);
		}else{
			cerr<<"kawaii";
			exit(123);
		}
	}

	return 0;
}