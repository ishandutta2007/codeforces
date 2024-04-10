#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int n,m,cnt[26];
char str[100100];

int main() {
	int ans=0;
	scanf("%d%d%s",&n,&m,str);

	for(int i=0;i<n;i++) cnt[str[i]-'A']++;
	printf("%d\n",*min_element(cnt,cnt+m)*m);

	return 0;
}