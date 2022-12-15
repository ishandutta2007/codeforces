#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		int u,v;
		scanf("%d%d",&u,&v);
		
		bool ans = u<=v;
		int uc=0, vc=0;
		for(int i=0;i<30;i++) {
			uc += u>>i&1;
			vc += v>>i&1;
			
			if(uc < vc) ans = false;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}