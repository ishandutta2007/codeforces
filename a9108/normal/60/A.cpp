#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

int l,r,n,m;
char s[10];

int main(){
	scanf("%d%d",&n,&m);
	l=1;r=n;
	for (int i=0;i<m;i++){
		scanf("%s",s);
		scanf("%s",s);
		scanf("%s",s);
		scanf("%s",s+1);
		int t;
		scanf("%d",&t);
		if (s[0]=='l') r=min(t-1,r);
		else l=max(l,t+1);
	}
	if (l<=r) printf("%d\n",r-l+1);
	else printf("-1\n");
	return 0;
}