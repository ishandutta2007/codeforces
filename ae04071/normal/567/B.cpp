#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9;

int n,t[101];
vector<int> qa[101];

int main() {
	scanf("%d",&n);
	set<int> tr;
	for(int i=1;i<=n;i++) {
		char ch;
		int val;
		scanf(" %c %d",&ch,&val);
		if(ch=='+') {
			tr.insert(val);
			t[i] = 1;
		} else {
			t[i] = 0;
			if(tr.find(val)==tr.end()) {
				qa[0].push_back(val);
			} else tr.erase(val);
		}
		qa[i].push_back(val);
	}
	t[0] = 1;

	int ans=0;
	tr.clear();
	for(int i=0;i<=n;i++) {
		while(!qa[i].empty()) {
			int cur = qa[i].back(); qa[i].pop_back();
			if(t[i]) tr.insert(cur);
			else tr.erase(cur);
		}
		ans = max(ans,sz(tr));
	}
	printf("%d\n",ans);

	return 0;
}