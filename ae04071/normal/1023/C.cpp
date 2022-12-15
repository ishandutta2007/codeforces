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

int n,m;
char str[200100];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",str);

	stack<char> stk;
	int k=n-m;
	for(int i=0;i<n;i++) {
		if(str[i]=='(') stk.push(str[i]);
		else {
			if(k) {
				stk.pop();
				k-=2;
			} else stk.push(str[i]);
		}
	}
	for(int i=0;i<m;i++) str[i]=stk.top(),stk.pop();
	reverse(str,str+m);
	for(int i=0;i<m;i++) printf("%c",str[i]);

	return 0;
}