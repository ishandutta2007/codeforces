#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int n,cache[1001000];
char s[1001000],t[1001000];

int main() {
	scanf("%d%s%s",&n,s,t);
	cache[0]=s[0]!=t[0];
	cache[1]=min(cache[0]+(s[1]!=t[1]),(s[0]!=t[1])+(s[1]!=t[0])+1);
	for(int i=2;i<n;i++) cache[i]=min(cache[i-1]+(s[i]!=t[i]),cache[i-2]+(s[i-1]!=t[i])+(s[i]!=t[i-1])+1);
	printf("%d\n",cache[n-1]);
	return 0;
}