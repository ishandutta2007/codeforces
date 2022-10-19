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

#define pb push_back
 
using namespace std;

priority_queue<pii> a;
priority_queue<pii> b;

vector<pii> A;
vector<pii> B;


main(){


		int n,x;
		scanf("%d%d",&n,&x);
		int x0 = x;

		for(int i=0;i<n;i++){
			int t;
			int h,m;
			scanf("%d%d%d",&t,&h,&m);
			if(t == 0)
				A.pb(pii(h,m));
			else
				B.pb(pii(h,m));
		}

		int pa=0, pb=0;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int ans = 0;

		while(pa < A.size() && A[pa].first <= x)
			a.push(pii(A[pa].second,A[pa].first)), pa++;
		while(pb < B.size() && B[pb].first <= x)
			b.push(pii(B[pb].second, B[pb].first)), pb++;

		int nn = 0;
		int cur = 0;
		
		while(nn < 2){

			pii k;
			if(cur == 0){
				if(a.size() == 0){nn++;continue;}
				k = a.top();
				a.pop();
			}
			if(cur == 1){
				if(b.size() == 0){nn++;continue;}
				k = b.top();
				b.pop();
			}
			x += k.first;

			ans++;

			while(pa < A.size() && A[pa].first <= x)
			a.push(pii(A[pa].second,A[pa].first)), pa++;
			while(pb < B.size() && B[pb].first <= x)
			b.push(pii(B[pb].second, B[pb].first)), pb++;

			cur ^= 1;
			nn = 0;

		}

		int ans2 = 0;
		cur = 1;
		nn = 0;
		while(a.size())a.pop();
		while(b.size())b.pop();
		pa = pb = 0;
		x = x0;
		while(pa < A.size() && A[pa].first <= x)
			a.push(pii(A[pa].second,A[pa].first)), pa++;
		while(pb < B.size() && B[pb].first <= x)
			b.push(pii(B[pb].second, B[pb].first)), pb++;
		

		while(nn < 2){

			pii k;
			if(cur == 0){
				if(a.size() == 0){nn++;continue;}
				k = a.top();
				a.pop();
			}
			if(cur == 1){
				if(b.size() == 0){nn++;continue;}
				k = b.top();
				b.pop();
			}
			x += k.first;

			ans2++;

			while(pa < A.size() && A[pa].first <= x)
			a.push(pii(A[pa].second,A[pa].first)), pa++;
			while(pb < B.size() && B[pb].first <= x)
			b.push(pii(B[pb].second, B[pb].first)), pb++;

			cur ^= 1;
			nn = 0;

		}
		
		

		printf("%d\n",max(ans,ans2));

}