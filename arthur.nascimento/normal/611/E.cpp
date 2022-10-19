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
#define maxn 200200

using namespace std;

int v[maxn];

int s[7][maxn];

int get(int t,int a,int b){
	int r = s[t][b];
	if(a)
		r -= s[t][a-1];
	return r;
}

main(){
	int n;
	scanf("%d",&n);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);

	if(a > b)
		swap(a,b);
	if(b > c)
		swap(b,c);
	if(a > b)
		swap(a,b);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	sort(v,v+n);

	if(v[n-1] > a+b+c){
		printf("-1\n");
		return 0;
	}

	for(int i=0;i<n;i++){
		if(i)
			for(int j=0;j<7;j++)
				s[j][i] += s[j][i-1];
			if(v[i] <= a)
				s[0][i]++;
			if(a < v[i] && v[i] <= b)
				s[1][i]++;
			if(b < v[i] && v[i] <= a+b)
				s[2][i]++;
			if(v[i] > a+b)
				s[3][i]++;
			if(v[i]-c <= a)
				s[4][i]++;
			if(a < v[i]-c && v[i]-c <= b)
				s[5][i]++;
			if(v[i] > a+b)
				s[6][i]++;
	}

	int ans0 = 0;
	while(n >= 1 && v[n-1] > b+c){
		n--;
		ans0++;
	}

	int low = 0, up = n;

	int pc = 0;
	while(pc < n-1 && v[pc+1] <= c)
		pc++;

	//low = 2, up = 3;
	while(low != up){

		int mid = (low+up)/2;
		debug("mid %d\n",mid);
		int ok = 0;

		for(int i=0;i<=mid;i++){

			debug("i=%d\n",i);
		
			int gr = mid - i;

			int cc1, cc2, ct1, ct2, ct1b, ct2b;

			ct1b = 1;
			ct2b = 0;

			cc2 = pc;
			cc1 = pc-i+1;
			if(cc1 < 0) cc1 = 0;

			if(v[0] > c){
				cc1 = 1;
				cc2 = 0;
			}

			ct2 = n-1;
			ct1 = ct2 - gr + 1;
			if(ct1 < 0) ct1 = 0;
			if(ct1 <= cc2){
				int off = cc2-ct1+1;
				ct2b = cc1-1;
				ct1b = ct2b-off+1;
				if(ct1b < 0) ct1b = 0;
				if(ct2b < 0){
					ct1b = 1;
					ct2b = 0;
				}
				ct1 = cc2+1;
			}
			if(v[n-1] <= c){
				ct1b = 1;
				ct2b = 0;
				ct2 = cc1-1;
				ct1 = ct2 - gr + 1;
				if(ct1 < 0) ct1 = 0;
			
			}

			debug("cc %d %d\nct %d %d\nctb %d %d\n",cc1,cc2,ct1,ct2,ct1b,ct2b);

			int AouB = get(0,0,n-1) - get(0,cc1,cc2) - get(0,ct1,ct2) - get(0,ct1b,ct2b);
			int AouB2 = get(4,ct1,ct2) + get(4,ct1b,ct2b);
			int AeB = get(2,0,n-1) - get(2,cc1,cc2) - get(2,ct1,ct2) - get(2,ct1b,ct2b);
			int B = get(1,0,n-1) - get(1,cc1,cc2) - get(1,ct1,ct2) - get(1,ct1b,ct2b);
			int B2 = get(5,ct1,ct2) + get(5,ct1b,ct2b);
			int falta = n - (cc2-cc1+1);

			int bad = get(6,0,n-1) - get(6,cc1,cc2) - get(6,ct1,ct2) - get(6,ct1b,ct2b);

			if(bad)
				continue;

			debug("AouB %d AeB %d B %d AouB2 %d\n",AouB,AeB,B,AouB2);

			int hb = mid, ha = mid;
			hb -= B;
			if(hb < 0) continue;
			hb -= AeB;
			ha -= AeB;
			if(ha < 0 || hb < 0) continue;
			
			hb -= B2;
			int dec = min(ha,B2);
			int pa = min(B2,min(ha,AouB));
			ha -= dec;
			AouB -= pa;

			if(hb < 0) continue;

			int p = min(min(ha,hb),min(AouB,AouB2));
			ha -= p;
			hb -= p;
			AouB -= p;
			AouB2 -= p;

			if(ha == 0 || hb == 0){
				if(ha+hb >= AouB+AouB2)
					ok = 1;
			}
			else if(AouB2 == 0){
				if(ha+hb >= AouB)
					ok = 1;
			}
			else if(AouB == 0){
				if(max(ha,hb) >= AouB2)
					ok = 1;
			}

		}

		if(ok)
			up = mid;
		else
			low = mid+1;

	}

	printf("%d\n",low+ans0);

}