#include <stdio.h>
#include <cstring>

int n, cnt[26];
char str[1000];

int main()
{
	gets(str);
	n=strlen(str);
	if(n==0) {
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<n;i++) {
		if(str[i]<'a'||str[i]>'z') {
			printf("NO\n");
			return 0;
		}
		cnt[str[i]-'a']=1;
	}

	bool flag=false;
	for(int i=0;i<26;i++) {
		if(cnt[i]) {
			if(flag) {
				printf("NO\n");
				return 0;
			}
		}
		else
			flag=true;
	}

	int idx=0;
	for(int i=0;i<n;i++) {
		int t=str[i]-'a';
		if(t>idx) {
			printf("NO\n");
			return 0;
		}
		else if(t==idx) {
			idx++;
		}
	}

	int c=0;
	for(int i=0;i<26;i++)
		if(cnt[i])c++;

	printf("YES\n");

	return 0;
}