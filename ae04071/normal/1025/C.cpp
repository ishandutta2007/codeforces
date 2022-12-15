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

char str[200100];
int n;

int main() {
	scanf("%s",str);
	n=strlen(str);

	int ans=0,c=0;
	for(int i=0;i<n;i++) str[i+n] = str[i];
	for(int i=0;i<n+n;i++){
		if(i==0 || str[i]==str[i-1]) c=1;
		else c++;
		ans = max(ans,c);
	}
	for(int i=n+n-1;i>=0;i--) {
		if(i==n+n-1 || str[i+1]==str[i]) c=1;
		else c++;
		ans = max(ans,c);
	}
	printf("%d\n",min(ans,n));

	return 0;
}