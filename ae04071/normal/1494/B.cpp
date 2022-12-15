#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		int n,c[4];
		scanf("%d",&n);
		for(int i=0;i<4;i++) scanf("%d",c+i);
		
		int chk = 0;
		for(int s=0;s<16;s++) {
			int f=1;
			for(int j=0;j<4;j++) {
				int v = (s>>j&1) + (s>>((j+1)%4)&1);
				if(c[j] < v || n-2+v < c[j]) f=0;
			}
			if(f) {
				chk=1;
				break;
			}
		}
		puts(chk ? "YES" : "NO");
	}
	
	return 0;
}