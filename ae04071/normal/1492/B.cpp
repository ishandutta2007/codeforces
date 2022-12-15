#include <bits/stdc++.h>
using namespace std;

int use[100001],pos[100001],arr[100001],n;
int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",arr+i);
		reverse(arr+1, arr+n+1);
		for(int i=1;i<=n;i++) pos[arr[i]] = i;
		fill(use,use+n+1,0);
		
		int tar = n, b = 0;
		while(tar) {
			if(!use[tar]) {
				for(int i = pos[tar]; i > b; i--) {
					printf("%d ",arr[i]);
					use[arr[i]] = 1;
				}
				b = pos[tar];
			}
			tar--;
		}
		puts("");
	}
	return 0;
}