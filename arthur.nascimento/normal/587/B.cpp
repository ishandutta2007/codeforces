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

#define inf 99999999999.
#define pii pair<int,int>
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
#define maxn 1001000

using namespace std;

pii arr[maxn];
int ps[maxn];
int top[maxn];
int n;

int get(int a,int b){
	int ret = ps[b];
	if(a) ret -= ps[a-1];
	return ret;
}

struct bit {

	int* T;
	int len;
	void clear(){
		len = 4*n;
		T = (int*) malloc((len)*sizeof(int));
		for(int i=0;i<len;i++)
			T[i] = 0;
	}
	void update(int idx,int val){
		//T[idx] += val;
		//return;
		//debug("update %d += %d\n",idx,val);
		idx++;
		while(idx < len){
			T[idx] = (T[idx]+val) % mod;
			idx += idx&-idx;
		}
	}
	int query(int idx){
		idx++;
		int ret = 0;
		while(idx){
			ret = (ret + T[idx]) % mod;
			idx -= idx&-idx;
		}
		return ret;
	}
	int get(int a,int b){
		//int rr = 0;
		//for(int i=a;i<=b;i++) rr += T[i];
		//return rr;
		int ret = query(b);
		if(a) ret -= query(a-1);
		if(ret < 0) ret += mod;
	//	debug("get %d %d ret %d\n",a,b,ret);
		return ret;
	}			

};

bit meio[maxn];
bit ult[maxn];


main(){

		int k;
		long long l;
		cin >> n >> l >> k;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i].first);
			arr[i].second = i;
		}

		long long blocks = l/n;
		if(l%n) blocks++;
		
		sort(arr,arr+n);
		
		int rem = l % n;
		for(int i=0;i<n;i++)
			if(arr[i].second < rem)
				ps[i]++;
		for(int i=1;i<n;i++)
			ps[i] += ps[i-1];
		top[0] = 0;
		for(int i=1;i<n;i++){
			if(arr[i].first == arr[i-1].first)
				top[i] = top[i-1];
			else
				top[i] = i;
		}


		for(int i=0;i<=k;i++){
			meio[i].clear();
			ult[i].clear();
		}

		for(int i=0;i<n;i++){
			ult[1].update(i,get(top[i],n-1));
			debug("ult[1][%d] = %d\n",i,get(top[i],n-1));
		}
		for(int i=0;i<n;i++){
			meio[1].update(i,n-top[i]);
			debug("meio[1][%d] = %d\n",i,n-top[i]);
		}
		
		for(int i=2;i<=k;i++){

			for(int j=0;j<n;j++){
				ult[i].update(j,ult[i-1].get(top[j],n-1));
				debug("ult[%d][%d] = %d (%d~%d)\n",i,j,ult[i-1].get(top[j],n-1),top[j],n-1);
			}
			for(int j=0;j<n;j++){
				meio[i].update(j,meio[i-1].get(top[j],n-1));
				debug("meio[%d][%d] = %d\n",i,j,meio[i-1].get(top[j],n-1));
			}
		}

		int ans = l%mod;

		for(int i=2;i<=k;i++){

			if(i > blocks) break;
			debug("i %d\n",i);

			ans += ult[i-1].get(0,n-1);
			debug(" + ult %d\n",ult[i-1].get(0,n-1));
			ans %= mod;

			long long qnt = blocks - i;
			if(qnt < 0) {
				qnt%=mod;
				qnt+=mod;
			}
			if(l%n == 0) qnt++;
			qnt %= mod;

			ans += ((long long)meio[i-1].get(0,n-1) * qnt) % mod;
			debug(" + mid %d\n",meio[i-1].get(0,n-1) * qnt);
			ans %= mod;
		
		}

		printf("%d\n",ans);

}