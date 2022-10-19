#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

struct node {
	int a,b,c;
	node(int a=0,int b=0,int c=0) : a(a), b(b), c(c) {}
	}
T[4*1001000];

char v[1001000];

node merge(node A,node B){

	node ret;
	ret.c = A.c + B.c + min(A.a, B.b);
	ret.a = B.a + max(0, A.a - B.b);
	ret.b = A.b + max(0, B.b - A.a);
	return ret;

}

void create(int init,int fim,int p){

		if(init == fim){
			if(v[init] == '(')
				T[p].a = 1;
			else
				T[p].b = 1;
			return;
			}

		create(init,(init+fim)/2,2*p);
		create((init+fim)/2+1,fim,2*p+1);

		T[p] = merge(T[2*p], T[2*p+1]);
		
	}

node query(int init,int fim,int p,int qx,int qy){

	if(fim < qx || init > qy)
		return node(0,0,0);

	if(init >= qx && fim <= qy)
		return T[p];

	return merge(query(init,(init+fim)/2,2*p,qx,qy), query((init+fim)/2+1,fim,2*p+1,qx,qy));

}

main(){

		int n,m;

		scanf(" %s",v);

		n = strlen(v);

		create(0,n-1,1);

		int q;
		scanf("%d",&q);

		for(int i=0;i<q;i++){

			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",2*query(0,n-1,1,a-1,b-1).c);

		}


}