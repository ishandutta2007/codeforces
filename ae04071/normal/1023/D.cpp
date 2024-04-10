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

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int MAX=1<<18;
struct tr{
	int tr[MAX<<1];
	void init() {
		for(int i=0;i<MAX+MAX;i++) tr[i] = MAX;
	}
	void upd(int cur,int val) {
		cur+=MAX;
		tr[cur] = min(tr[cur],val);
		cur>>=1;
		while(cur) {
			tr[cur] = min(tr[cur<<1],tr[cur<<1|1]);
			cur>>=1;
		}
	}
	int find(int l,int r) {
		l+=MAX; r+=MAX;
		int res=MAX;
		while(l<=r) {
			res = min(res, min(tr[l],tr[r]));
			if(l&1)l++;
			if(!(r&1))r--;
			l>>=1; r>>=1;
		}
		return res;
	}
}tr;
int n,m,arr[200001],mn[200001],mx[200001];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) mn[i]=n;
	tr.init();

	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		if(arr[i]==0) tr.upd(i,MAX);
		else tr.upd(i,arr[i]);
		mn[arr[i]] = min(mn[arr[i]],i);
		mx[arr[i]] = max(mx[arr[i]],i);
	}
	for(int i=1;i<=m;i++) {
		if(tr.find(mn[i],mx[i])<i) {
			puts("NO");
			return 0;
		}
	}

	int f=0;
	for(int i=0;i<n;i++) if(arr[i]==m) {
		f=1;
		break;
	}
	if(!f) {
		for(int i=0;i<n;i++) if(arr[i]==0) {
			arr[i]=m;
			f=1;
			break;
		}
		if(!f) {
			puts("NO");
			return 0;
		}
	}

	puts("YES");

	stack<int> stk;
	for(int i=0;i<n;i++) {
		while(!stk.empty() && arr[i]!=0) {
			arr[stk.top()] = arr[i];
			stk.pop();
		}
		if(arr[i]==0 && i!=0 && arr[i-1]!=0) arr[i]=arr[i-1];
		else if(arr[i]==0) stk.push(i);
	}
	if(!stk.empty()) for(int i=0;i<n;i++) arr[i] = m;

	for(int i=0;i<n;i++) printf("%d ",arr[i]);

	return 0;
}