#include <stdio.h>
#include <cstring>
#include <string>

char str[100010];
std::string tmp="Bulbasaur";
int cnt[80];
int n;

int main()
{
	scanf("%s",str);
	n=strlen(str);
	int j=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<tmp.size();j++) {
			if(tmp[j]==str[i]) {
				cnt[j]++;
			}
		}
	}
	int min=987654321;
	for(int i=0;i<tmp.size();i++) {
		int c=cnt[i];
		if(i==4 || i == 6 || i == 1 | i == 7)
			c/=2;

		if(min>c) {
			min=c;
		}
	}
	printf("%d\n",min);

	return 0;
}