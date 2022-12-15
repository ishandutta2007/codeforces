#include <stdio.h>
#include <cstring>
#include <algorithm>

int n,m;
char s[200100], p[200100];
int pi[200100];
int arr[200100];

char str[200100];
bool chk[200100];

void getPi() {
	int j=0;
	for(int i=1;i<m;i++) {
		while(j!=0 && p[i]!=p[j])
			j=pi[j-1];
		if(p[i]==p[j]){
			pi[i]=++j;
		}
	}
}

bool kmp(int len) {
	int j=0;
	for(int i=0;i<len;i++) {
		if(str[i]==p[j]) j++;
		if(j==m) return true;
	}
	return false;
}
bool Check(int md) {
	std::fill(chk, chk+n, false);
	for(int i=0;i<md;i++) 
		chk[arr[i]]=true;
	memset(str, 0, sizeof(str));
	int len=0;
	for(int i=0;i<n;i++) {
		if(!chk[i]) 
			str[len++]=s[i];
	}
	return kmp(len);
}

int main() {
	scanf("%s",s); n=strlen(s);
	scanf("%s",p); m=strlen(p);
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i); arr[i]--;
	}

	getPi();
	int lo=0, up=n;
	while(up-lo>1) {
		int md=(lo+up)/2;
		if(Check(md))
			lo=md;
		else 
			up=md;
	}
	printf("%d\n",lo);

	return 0;
}