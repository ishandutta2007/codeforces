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

#define inf (9999999999999999LL)
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
#define maxn 300300
#define sq(x) ((x)*(x))	

using namespace std;

int vv[maxn];

int maxI[maxn];
int minI[maxn];

int s[2*maxn];
int last[2*maxn];
int cur = 0;

long long conta2(int n,int mid,int pode){

	cur++;
	debug("conta2 ");
	for(int i=0;i<n;i++) debug("%d ",vv[i]);
	debug("mid %d\n",mid);
	
	maxI[mid+1] = minI[mid+1] = vv[mid+1];

	for(int i=mid+2;i<n;i++){
		maxI[i] = max(maxI[i-1],vv[i]);
		minI[i] = min(minI[i-1],vv[i]);
	}

	int pma = mid+1;
	int pmi = mid+1;

	int maxcur = vv[mid];
	int mincur = vv[mid];

	long long ret = 0;

	vector<pii> tira;
	vector<pii> soma;

	for(int i=mid-1;i>=0;i--){
	
		mincur = min(mincur,vv[i]);
		maxcur = max(maxcur,vv[i]);
		//if(maxcur > vv[i]) continue;
		while(pma < n && maxI[pma+1] < maxcur) pma++;
		while(pmi < n && minI[pmi] > mincur) pmi++;

		if(maxcur == vv[mid] && !pode) continue;

		int len = maxcur-mincur+1;
		int fim = i + len-1;

		debug("i=%d %d~%d\n",i,pmi,pma);
		debug("testa off %d min %d max %d\n",fim,mincur,maxcur);
		if(pmi > pma || fim < pmi || fim > pma)
			if(fim > mid && fim < n && maxI[fim] <= maxcur && minI[fim] >= mincur) {debug("!!");ret++;}	

		

		if(pma >= pmi && pmi != n){
			int u = maxcur + i;
			debug("look %d (%d~%d)\n",u,pmi,pma);
			if(pmi-1 > mid)tira.pb(pii(pmi-1,u));
			soma.pb(pii(pma,u));
		}

	}

	map<int,int> mp;

	sort(tira.begin(), tira.end());
	sort(soma.begin(), soma.end());

	int ptira = 0;
	int psoma = 0;

	for(int i=mid+1;i<=n;i++){

		if(i != n)debug("%d is %d\n",i,i+minI[i]);
		if(i != n){
			if(last[i+minI[i]] != cur)last[i+minI[i]] = cur, s[i+minI[i]] = 0;
			s[i+minI[i]]++;
		}
		while(ptira < tira.size() && tira[ptira].first == i){if(last[tira[ptira].second]==cur) ret -= s[tira[ptira].second]; ptira++;}
		while(psoma < soma.size() && soma[psoma].first == i){if(last[soma[psoma].second]==cur) ret += s[soma[psoma].second]; psoma++;}

	}	



	debug("ret %I64d\n",ret);
	return ret;

}


int v[maxn];

long long conta(int a,int b){

	if(a == b) return 1;
	if(b == a+1){
		if(abs(v[b]-v[a]) == 1) return 3;
		return 2;
	}
	debug("go %d..%d\n",a,b);

	int mid = (a+b)/2;

	
	long long ret = conta(a,mid);
	ret += conta(mid,b) - 1;

	for(int i=a;i<=b;i++)
		vv[i-a] = v[i];
	
	long long u = 0;
	u += conta2(b-a+1,mid-a,1);

	int l = vv[mid-a];

	for(int i=0;i<b-a+1;i++) debug(" %d",vv[i]);
	reverse(vv,vv+b-a+1);

	long long uu = conta2(b-a+1,(b-a+1)/2,0);
	assert(vv[(b-a+1)/2] == l);

	
	debug(" -> %I64d + %I64d\n",u,uu);

	debug("ret %I64d\n",ret+u+uu);
	return ret+u+uu;

}

long long brute(int n){
	long long ret = 0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){

			int ma = 0, mi = n;
			for(int k=i;k<=j;k++)
				ma = max(ma,v[k]), mi = min(mi,v[k]);

			if(ma-mi == j-i) ret++;
		
		}

	return ret;

}

main(){

		int n;
		srand(time(0));
		while(0){
			n = 7;
			for(int i=0;i<n;i++) v[i] = i;
			random_shuffle(v,v+n);
			debug("\n\n\n\n");
			for(int i=0;i<n;i++) debug("%d ",v[i]);
			long long A = brute(n), B = conta(0,n-1);
			debug("%I64d %I64d\n",A,B);
			assert(A == B);
		}

		
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			v[a] = b;
		}

		cout << conta(0,n-1) << endl;

}