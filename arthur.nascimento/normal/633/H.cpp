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

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 30300

typedef long long ll;
using namespace std;


long double x, x_;

int cur[maxn];
long double v[maxn];

int num[maxn];

long double mod;



int sqn = 200;

struct query {
	int l, r, idx;
	query(int l=0,int r=0,int idx=0): l(l), r(r), idx(idx) {}
	bool operator<(query comp)const{ 
		if(l/sqn != comp.l/sqn)
			return l/sqn < comp.l/sqn;
		return r < comp.r;
	}
};

int mp[maxn];

int ans[maxn];
int qual[maxn];

int nxt[maxn];
int beg;

int fib[maxn];

int rt;
char ch;
inline int read(){
	rt = 0;
	while((ch=getchar()) >= '0')
		rt = 10*rt + ch-'0';
	return rt;
}

main(){

		int n = read();
		int md = read();
	
		fib[1] = fib[2] = 1;
		for(int i=3;i<=n;i++)
			fib[i] = (fib[i-1]+fib[i-2])%md;

		vector<pii> u;

		for(int i=0;i<n;i++){
			int a = read();
			//a %= md;
			//v[i] = a%md;
			u.pb(pii(a,i));
			//v[i] = fmod(v[i],mod);
		}

		
		sort(u.begin(), u.end());

		qual[u[0].second] = 0;
		num[0] = u[0].first;
		for(int i=1;i<n;i++){
			if(u[i].first == u[i-1].first)
				qual[u[i].second] = qual[u[i-1].second];
			else
				qual[u[i].second] = 1 + qual[u[i-1].second];
			
			num[qual[u[i].second]] = u[i].first;
		}

		int q = read();

		for(int i=0;i<n;i++)
			num[i] %= md;

		vector<query> Q;

		for(int i=0;i<q;i++){
			int l, r;
			l = read()-1;
			r = read()-1;
			Q.pb(query(l,r,i));
		}

		sort(Q.begin(), Q.end());

		int l = 0, r = -1;

		set<int> S;

		for(int i=0;i<q;i++){

			while(r < Q[i].r){
				r++;
				if(mp[qual[r]] == 0){
					
					
					//update(0,n-1,1,qual[r]);
					S.insert(qual[r]);
					set<int> :: iterator it = S.upper_bound(qual[r]);
					if(it != S.end()){
						nxt[qual[r]] = *it;
					}
					else nxt[qual[r]] = -1;
					it--;
					if(it == S.begin())
						beg = *it;
					else {
						it--;
						nxt[*it] = qual[r];
					}
				}
				mp[qual[r]]++;
			}
			while(l > Q[i].l){
				l--;
				if(mp[qual[l]] == 0){
					
					S.insert(qual[l]);
					set<int> :: iterator it = S.upper_bound(qual[l]);
					if(it != S.end()){
						nxt[qual[l]] = *it;
					}
					else nxt[qual[l]] = -1;
					it--;
					if(it == S.begin())
						beg = *it;
					else {
						it--;
						nxt[*it] = qual[l];
					}
					//update(0,n-1,1,qual[l]);
				}
				mp[qual[l]]++;
			}
			while(r > Q[i].r){
				if(mp[qual[r]] == 1){
					
					S.erase(qual[r]);
					set<int> :: iterator it = S.lower_bound(qual[r]);
					if(it == S.begin())
						beg = *it;
					else if(it == S.end()){
						it--;
						nxt[*it] = -1;
					}
					else {
						set<int> :: iterator it2 = it;
						it2--;
						nxt[*it2] = *it;
					}
					//update(0,n-1,1,qual[r]);
				}
				mp[qual[r]]--;
				r--;
			}
			while(l < Q[i].l){
				if(mp[qual[l]] == 1){
					
					//update(0,n-1,1,qual[l]);
					S.erase(qual[l]);
					set<int> :: iterator it = S.lower_bound(qual[l]);
					if(it == S.begin())
						beg = *it;
					else if(it == S.end()){
						it--;
						nxt[*it] = -1;
					}
					else {
						set<int> :: iterator it2 = it;
						it2--;
						nxt[*it2] = *it;
					}
				}
				mp[qual[l]]--;
				l++;
			}

			ll cur = 0;
			for(int j=beg, k=1; j != -1; j = nxt[j], k++)
				cur = (cur + fib[k] * num[j]) % md;
			//debug("Q %d %d~%d %d %d\n",Q[i].idx,Q[i].l,Q[i].r,l,r);
			ans[Q[i].idx] = cur;
			

		}

		for(int i=0;i<q;i++)
			printf("%d\n",(ans[i]%md+md)%md);

}