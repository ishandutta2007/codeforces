#include <stdio.h>

int n;
char str[200010];
bool flag[200010];

int sd, sr;

int main()
{
	scanf("%d",&n);
	scanf("%s",str);

	for(int i=0;i<n;i++) {
		if(str[i]=='D') sd++;
		else sr++;
	}

	int i=0;

	int dd=0,rr=0;
	while(true)
	{
		if(sd==0 || sr==0) break;
		if(str[i]=='D') {
			if(!flag[i]) {
				if(rr==0) {
					sr--;
					dd++;
				}
				else {
					rr--;
					flag[i]=true;
				}
			}
		}
		else {
			if(!flag[i]) {
				if(dd==0) {
					sd--;
					rr++;
				}
				else {
					dd--;
					flag[i]=true;
				}
			}
		}
		i++;
		if(i>=n) i=0;
	}

	if(sd==0)printf("R");
	else printf("D");

	return 0;
}