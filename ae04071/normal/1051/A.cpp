#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>

using namespace std;

char str[101];

char get(int i) {
	if(i==0) return '0';
	else if(i==1) return 'a';
	else return 'A';
}


int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%s",str);
		int n=strlen(str);

		int f=0,cnt=0;
		for(int i=0;i<n;i++) {
			if(isdigit(str[i])) f|=1;
			else if(islower(str[i])) f|=2;
			else f|=4;
		}

		for(int j=0;j<3;j++) cnt+=f>>j&1;

		if(cnt==3)printf("%s\n",str);
		else if(cnt==2) {
			int c[3]={0,};
			for(int i=0;i<n;i++) {
				if(isdigit(str[i])) c[0]++;
				else if(islower(str[i])) c[1]++;
				else c[2]++;
			}
			for(int i=0;i<n;i++) {
				int f=0;
				if(isdigit(str[i]) && c[0]>1) f=1;
				else if(islower(str[i]) && c[1]>1) f=1;
				else if(isupper(str[i]) && c[2]>1) f=1;
				if(f) {
					for(int j=0;j<3;j++) if(!c[j]) {
						str[i] = get(j);
						break;
					}
					break;
				}
			}
			printf("%s\n",str);
		} else {
			if(isdigit(str[0])) {
				str[0] = get(1); str[1] = get(2);
			} else if(islower(str[0])) {
				str[0]=get(0); str[1]=get(2);
			} else{
				str[0]=get(0); str[1]=get(1);
			}
			printf("%s\n",str);
		}
	}
	return 0;
}