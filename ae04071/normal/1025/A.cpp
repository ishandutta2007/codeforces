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

char str[100100];
int n,cnt[26];

int main() {
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++) cnt[str[i]-'a']++;
	if(n==1) {
		puts("YES");
		return 0;
	}
	int f=0;
	for(int i=0;i<26;i++) if(cnt[i]>=2) f++;
	puts(f<1 ? "NO" : "YES");
	
	return 0;
}