#include <iostream>
#include <iomanip>
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

#define inf (999999999999LL)
#define pii pair<long long,long long>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

struct segtree {

	pii T[4*maxn];
	int n;

	void update(int init,int fim,int p,int pos,long long val){

		if(pos > fim || pos < init) return;

		if(init == fim){
			T[p].first = T[p].second = val;
			return;
		}

		int mid = (init+fim)/2;

		update(init,mid,2*p,pos,val);
		update(mid+1,fim,2*p+1,pos,val);

		T[p].first = max(T[2*p].first,T[2*p+1].first);
		T[p].second = min(T[2*p].second,T[2*p+1].second);

	}

	pii query(int init,int fim,int p,int l,int r){

		if(l > fim || r < init) return pii(-inf,inf);

		if(init >= l && fim <= r)
			return T[p];

		int mid = (init+fim)/2;

		pii A = query(init,mid,2*p,l,r);
		pii B = query(mid+1,fim,2*p+1,l,r);

		return pii(max(A.first,B.first),min(A.second,B.second));

	}

	void build(int N,int*v){
		n = N;
		for(int i=0;i<n;i++)
			update(0,n-1,1,i,v[i]);
	}

};

int v[maxn];
int nil[maxn];

segtree arr;
segtree dp;

main(){

		long long n,s,l;
		cin >> n >> s >> l;

		for(int i=0;i<=n;i++)nil[i] = 0;

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		arr.build(n,v);
		dp.build(n+1,nil);

		int righty = n-1;

		for(int i=n-1;i>=0;i--){

			while(righty > i){
				pii k = arr.query(0,n-1,1,i,righty);
				if(k.first-k.second > s) righty--;
				else break;
			}

			int lefty = i + l - 1;

			long long ans;

			if(lefty > righty)
				ans = inf;
			else
				ans = 1 + dp.query(0,n,1,lefty+1,min(n,(long long)righty+1)).second;

			debug("i = %d ans = %I64d lr = %d %d\n",i,ans,lefty,righty);

			dp.update(0,n,1,i,ans);

		}

		long long resp = dp.query(0,n,1,0,0).first;

		if(resp >= inf)
			printf("-1\n");
		else
			cout << resp << endl;

}