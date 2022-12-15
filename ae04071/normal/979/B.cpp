#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <map>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

char str[100100];

int get(char ch) {
	if(islower(ch)) return ch-'a';
	else return ch-'A'+26;
}

int main() {
	int n;
	scanf("%d",&n);

	int mm=0,mi=-1;
	for(int i=0;i<3;i++) {
		scanf("%s",str);

		int l=strlen(str),cnt[60]={0,};
		for(int j=0;j<l;j++) {
			cnt[get(str[j])]++;
		}
		
		int mx=0;
		for(int j=0;j<52;j++) mx=max(mx,cnt[j]);

		int val;
		if(mx==l) {
			if(n==1) val=mx-1;
			else val=mx;
		}
		else val=min(l,mx+n);
		
		if(mm<val) {
			mm=val;
			mi=i;
		}
		else if(mm==val) {
			mi=-2;
		}
	}
	if(mi==-2) puts("Draw");
	else if(mi==0) puts("Kuro");
	else if(mi==1) puts("Shiro");
	else puts("Katie");
}