#include <bits/stdc++.h>
using namespace std;

char str[10][10];
int n;

int main() {
	n=8;
	for(int i=0;i<n;i++) scanf("%s",str[i]);

	int wc=10,bc=10;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		if(str[i][j] == 'W')  {
			int f=1;
			for(int k=i-1;k>=0;k--) if(str[k][j]!='.') {
				f=0;
				break;
			}
			if(f) wc = min(wc, i);
		}
		else if(str[i][j]=='B') {
			int f=1;
			for(int k=i+1;k<n;k++) if(str[k][j]!='.') {
				f=0;
				break;
			}
			if(f) bc = min(bc,n-i-1);
		}
	}
	puts( wc<=bc ? "A" : "B");
	
	return 0;
}