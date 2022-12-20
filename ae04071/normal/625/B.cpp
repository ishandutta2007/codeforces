#include <stdio.h>
#include <cstring>

char str[100100];
char c[40];

int main()
{
	int cnt=0;
	scanf("%s",str);
	scanf("%s",c);

	int n1=strlen(str), n2=strlen(c);
	for(int i=0;i<n1;i++) {
		int j=0;
		for(;j<n2 && i+j<n1;j++) {
			if(str[i+j]!=c[j]) break;
		}
		if(j==n2) {
			str[i+n2-1]='#';
			cnt++;
		}
	}

	printf("%d\n",cnt);

	return 0;
}