#include <bits/stdc++.h>
using namespace std;

char s[1000001],t[1000001];
int n,pi[1000001];

void getpi(char *str,int n) {
	int i=0;
	for(int j=1;j<n;j++) {
		while(i!=0 && str[i]!=str[j]) i = pi[i-1];
		if(str[i] == str[j]) pi[j] = ++i;
		else pi[j] = 0;
	}
}
int kmp(char *s,char *t,int n,int m) {
	int i=0;
	for(int j=0;j<m;j++) {
		while(i!=0 && s[i]!=t[j]) i=pi[i-1];
		if(s[i] == t[j]) {
			++i;
		}
		if(i && m - (j-i+1) <= i*2+1) return m - (j-i+1);
	}
	return 1;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%s",s);
		n = strlen(s);

		int l=0,r=n-1;
		while(l<r) {
			if(s[l]!=s[r]) break;
			l++; r--;
		}
		if(l>=r) {
			printf("%s\n", s);
		} else {
			int m = r-l+1;
			memcpy(t, s+l, m);
			reverse(t,t+m);
			getpi(s+l, m);
			
			int a1 = kmp(s+l, t, m, m);
			getpi(t, m);
			int a2 = kmp(t, s+l, m, m);
			if(a1 >= a2) {
				for(int i=0;i<l+a1;i++) printf("%c",s[i]);
				for(int i=r+1;i<n;i++) printf("%c",s[i]);
			} else {
				for(int i=0;i<l;i++) printf("%c",s[i]);
				for(int i=r-a2+1;i<n;i++) printf("%c",s[i]);
			}
			puts("");
		}
	}
	return 0;
}