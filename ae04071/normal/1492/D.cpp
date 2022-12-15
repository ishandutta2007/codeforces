#include <bits/stdc++.h>
using namespace std;

int a,b,k;

int main() {
	scanf("%d%d%d",&a,&b,&k);
	if(k==0) {
		puts("Yes");
		for(int t=0;t<2;t++) {
			for(int i=0;i<b;i++) printf("1");
			for(int i=0;i<a;i++) printf("0");
			puts("");
		}
		return 0;
	}
	if(k>a+b-2 || (b==1 && k!=0) || (a==0 && k!=0)) {
		puts("No");
		return 0;
	}
	puts("Yes");

	if(b==1) {
		for(int t=0;t<2;t++) {
			printf("1");
			for(int i=0;i<a;i++) printf("0");
			puts("");
		}
		return 0;
	}
	if(a==0) {
		for(int t=0;t<2;t++) {
			for(int i=0;i<b;i++) printf("1");
			puts("");
		}
		return 0;
	}

	printf("1");
	for(int i=0;i<b-2-max(k-a, 0);i++) printf("1");
	for(int i=0;i<max(a-k,0);i++) printf("0");
	printf("1");
	for(int i=0;i<max(k-a, 0);i++) printf("1");
	for(int i=0;i<min(k,a); i++) printf("0");
	puts("");

	printf("1");
	for(int i=0;i<b-2-max(k-a, 0);i++) printf("1");
	for(int i=0;i<max(a-k,0);i++) printf("0");
	printf("0");
	for(int i=0;i<max(k-a, 0);i++) printf("1");
	for(int i=0;i<min(k,a)-1; i++) printf("0");
	printf("1");

	return 0;
}