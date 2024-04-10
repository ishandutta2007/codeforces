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
#define mod 1000000007
#define maxn 110

typedef long long ll;
using namespace std;

vector<pii> v[maxn][maxn];

int n;

int uni(int a,int b,vector<pii> &r){

	if(a == n+1)
		a = 0;
	if(b == -1 || b < a)
		a = 1, b = 0;

	sort(r.begin(),r.end());
	int ret = 0;

	int s = 0;

	int last = -inf;

	int pa = 0, pb = 0;
	while(pa < v[a][b].size() || pb < r.size()){

		int u = 0;
		if(pa == v[a][b].size() || (pb != r.size() && v[a][b][pa].first > r[pb].first))
			u = 1;

		if(u == 0){
			if(last != -inf)
				if(s)
					ret += v[a][b][pa].first-last;
			s += v[a][b][pa].second;
			last = v[a][b][pa].first;
			pa++;
		}
		else {
			if(last != -inf)
				if(s)
					ret += r[pb].first-last;
				s += r[pb].second;
				last = r[pb].first;
				pb++;
			}
		}

	return ret;

}

pii a[maxn];

int dp[maxn][maxn][maxn];

int get(int pos,int left,int right){

	if(dp[pos][left][right]+1)
		return dp[pos][left][right];

	if(pos == n)
		return 0;

	int ret = 0;

	vector<pii> r,s;
	r.pb(pii(a[pos].first,1));
	r.pb(pii(a[pos].first+a[pos].second,-1));
	r.pb(pii(a[right].first,1));
	r.pb(pii(a[right].first+a[right].second,-1));
	s.pb(pii(a[right].first,1));
	s.pb(pii(a[right].first+a[right].second,-1));

	if(left != n){
		r.pb(pii(a[left].first-a[left].second,1));
		r.pb(pii(a[left].first,-1));
		s.pb(pii(a[left].first-a[left].second,1));
		s.pb(pii(a[left].first,-1));
	}
	
	int A = uni(left+1,pos-1,s);

	ret = get(pos+1,left,right) + uni(left+1,pos-1,r) - A;

	r.clear();
	r.pb(pii(a[pos].first-a[pos].second,1));
	r.pb(pii(a[pos].first,1));
	r.pb(pii(a[right].first,1));
	r.pb(pii(a[right].first+a[right].second,-1));
	if(left != n){
		r.pb(pii(a[left].first-a[left].second,1));
		r.pb(pii(a[left].first,-1));
	}

	int B = uni(left+1,pos-1,r);

	if(pos == 2 && left == 3 && right == 3)
		debug("A %d B %d\n",A,B);

	if(B > A && (left == n || a[pos].first-a[pos].second >= a[left].first-a[left].second)){
		int r = right;
		int best = a[r].first+a[r].second;
		for(int i=(left==n)?0:left+1;i<pos;i++)
			if(a[i].first+a[i].second > best){
				best = a[i].first+a[i].second;
				r = i;
			}
		if(pos == 1 && left == 0 && right == 3)
			debug("call %d %d %d\n",pos+1,pos,r);
		ret = max(ret, B-A + get(pos+1,pos,r));
	}
	debug("dp[%d][%d][%d] = %d\n",pos,left,right,ret);
	return dp[pos][left][right] = ret;

}

int foi[30];
int mrk[110];

int brute(int){

	int ret = 0;

	for(int i=0;i<(1<<n);i++){

		memset(mrk,0,sizeof(mrk));
		for(int j=0;j<n;j++){
			int l, r;
			if(i & (1<<j))
				l = a[j].first, r = a[j].first+a[j].second; 
			else
				l = a[j].first-a[j].second, r = a[j].first;
			for(int j=l;j<r;j++)	
			mrk[j+30] = 1;
		}

		int cur = 0;
		for(int j=0;j<100;j++)
			cur += mrk[j];
		ret = max(ret,cur);

	}
	debug("brute %d\n",ret);
	return ret;
		
}

main(){
	srand(time(0));
	scanf("%d",&n);
	//while(1){

	memset(foi,0,sizeof(foi));

	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
		
	/*for(int i=0;i<n;i++){
		a[i].first = rand()%20;
		a[i].second = rand()%20;
		while(foi[a[i].first])
			a[i].first = rand()%20;
		foi[a[i].first] = 1;
		printf("%d %d\n",a[i].first,a[i].second);
	}*/	
		

	sort(a,a+n);

	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			v[i][j].clear();
			for(int k=i;k<=j;k++){
				v[i][j].pb(pii(a[k].first,1));
				v[i][j].pb(pii(a[k].first+a[k].second,-1));
			}
			sort(v[i][j].begin(), v[i][j].end());
		}

	memset(dp,-1,sizeof(dp));

	printf("%d\n\n",get(0,n,n));
	//assert(get(0,n,n) == brute(n));
	//}

}