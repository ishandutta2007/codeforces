#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define pcc pair<char,char>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

int n;

#define sq 1500

struct query {
	int l, r, id;
	bool operator<(query comp)const{
		if(l/sq != comp.l/sq)
			return l/sq < comp.l/sq;
		return r < comp.r;	
	}
}

Q[maxn];

int resp[maxn];
int v[maxn];

#define count iflegr

int freq[maxn];
int inside[maxn];
int count[maxn];

int aux[maxn];

int ret;
char ch;

int u = 0;

inline int read(){
	ret = 0;//return 0;
	while((ch=getchar()) >= '0')
		ret = 10*ret+ch-'0';
	return ret;
}

map<pii,ll> mp;

main(){

	n = read();
	//n = 100000;

	for(int i=0;i<n;i++){
		v[i] = read();
		//v[i] = i+1;
	}

	int q = read();
	//q = 100000;
	
	for(int i=0;i<q;i++){
		Q[i].l = read();
		Q[i].r = read();
	//	Q[i].l = 1;
	//	Q[i].r = 100000;
		Q[i].l--;
		Q[i].r--;
		Q[i].id = i;
	}

	sort(Q,Q+q);

	int l = 0, r = -1;

	set<int> big;

	for(int i=0;i<q;i++){

		if(mp.find(pii(Q[i].l,Q[i].r)) != mp.end()){
			resp[Q[i].id] = mp[pii(Q[i].l,Q[i].r)];
			continue;
		}

		while(r < Q[i].r){
			r++;
			count[freq[v[r]]]--;
			freq[v[r]]++;
			//debug("+ %d\n",v[r]);
			count[freq[v[r]]]++;
			if(freq[v[r]] >= sq && !inside[v[r]]){
				inside[v[r]] = 1;
				big.insert(v[r]);
			}
		}

		while(l < Q[i].l){
			count[freq[v[l]]]--;
			freq[v[l]]--;
			count[freq[v[l]]]++;
			if(freq[v[l]] < sq/2 && inside[v[l]]){
				inside[v[l]] = 0;
				big.erase(v[l]);
			}
			l++;
		}

		while(r > Q[i].r){
			count[freq[v[r]]]--;
			freq[v[r]]--;
			count[freq[v[r]]]++;
			if(freq[v[r]] < sq/2 && inside[v[r]]){
				inside[v[r]] = 0;
				big.erase(v[r]);
			}
			r--;
		}

		while(l > Q[i].l){
			l--;
			count[freq[v[l]]]--;
			freq[v[l]]++;
			//debug("+ %d\n",v[l]);
			count[freq[v[l]]]++;
			if(freq[v[l]] >= sq && !inside[v[l]]){
				inside[v[l]] = 1;
				big.insert(v[l]);
			}
		}

		priority_queue<int> PQ;

	#define insert push

		for(set<int> :: iterator it = big.begin(); it != big.end(); it++)
			if(freq[*it] >= sq)
				PQ.insert(-freq[*it]);

		ll ans = 0;

		for(int j=1;j<sq;j++)
			aux[j] = 0;

		int b = -1;
		int a, k;
		
		for(int j=1;j<sq;j++){
			a = count[j]+aux[j];
		//	debug("a[%d] = %d aux %d\n",j,a,aux[j]);

			if(a == 0) continue;
			if(b+1){
				ans += b+j;
				a--;
				if(b+j < sq)
					aux[b+j]++;
				else
					PQ.insert(-b-j);
				b = -1;
			}
			if(a == 0) continue;
			if(a&1) b = j;
			ans += 2 * j * (a>>1);
			if(2*j < sq)
				aux[2*j] += (a>>1);
			else
				for(k=0;k<(a>>1);k++)
					PQ.insert(-2*j);
		}

		if(b+1)
			PQ.insert(-b);

		int x, y;

		//debug("size %d\n",(int)PQ.size());

		while(PQ.size()){
			x = PQ.top();
			PQ.pop();
			if(PQ.size() == 0) continue;
			y = PQ.top();
			PQ.pop();
			ans += -x-y;
			PQ.insert(x+y);
		}

		mp[pii(Q[i].l,Q[i].r)] = ans;
		resp[Q[i].id] = ans;

	}

	for(int i=0;i<q;i++)
		printf("%d\n",resp[i]);

}