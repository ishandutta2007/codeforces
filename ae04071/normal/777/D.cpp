#include <stdio.h>
#include <algorithm>
#include <string>

int n;
char s[500100];
std::string str[500010];
int size[500010];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		str[i]=s;
		size[i]=str[i].size();
	}

	for(int i=n-2;i>=0;i--) {
		int midx=std::min(size[i+1],size[i]);
		int j=0;
		for(j=0;j<midx;j++) {
			if(str[i][j]!=str[i+1][j]) {
				if(str[i][j]>str[i+1][j])
					size[i]=j;
				break;
			}
		}
		if(j==midx)
			size[i]=j;
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<size[i];j++) {
			printf("%c",str[i][j]);
		}
		puts("");
	}

	return 0;
}