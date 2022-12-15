#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctype.h>
#include <assert.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,arr[501][501],t[502],ot[502];
char str[10];

char res[2010];

int get(char *str) {
	if(!strcmp(str,"YES")) return 1;
	else if(!strcmp(str,"NO")) return 0;
	else return -1;
}

int main() {
	scanf("%d",&n);

	for(int i=1;i<=n;i++) {
		int val=1;
		printf("? %d %d %d %d\n",1,1,n-i+1,i);

		fflush(stdout);
		scanf("%s",str);
		if(get(str)==-1) return 0;
		val &= get(str);

		printf("? %d %d %d %d\n",n-i+1,i,n,n);
		fflush(stdout);
		scanf("%s",str);
		if(get(str)==-1) return 0;
		val &= get(str);

		ot[i] = t[i] = val;
	}

	for(int i=n-1;i;i--) 
		t[i] |= t[i+1];

	int cr=1,cc=1;
	vector<pii> ans,rans;
	while(cr+cc<n+1) {
		ans.push_back(pii(cr,cc));
		if(cc+1>n || !t[cc+1]) cr++;
		else {
			printf("? %d %d %d %d\n",cr,cc+1,n,n);
			fflush(stdout);
			scanf("%s",str);

			if(get(str)==-1) return 0;

			if(get(str)) cc++;
			else cr++;
		}
	}
	ans.push_back(pii(cr,cc));

	int v=cc,vv=cr;
	cr=n;cc=n;
	while((n-cr+1) + (n-cc+1) < n+1) {
		rans.push_back(pii(cr,cc));
		if(cc==v) cr--;
		else if(cr==vv) cc--;
		else {
			printf("? %d %d %d %d\n",1,1,cr-1,cc);
			fflush(stdout);
			scanf("%s",str);

			if(get(str)==-1) return 0;
			if(get(str)) cr--;
			else cc--;
		}
	}

	reverse(rans.begin(),rans.end());
	ans.insert(ans.end(),rans.begin(),rans.end());

	for(int i=0;i<sz(ans)-1;i++) {
		if(ans[i].fi==ans[i+1].fi) res[i] = 'R';
		else res[i] = 'D';
	}
	printf("! %s\n",res);

	return 0;
}