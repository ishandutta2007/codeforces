#include <stdio.h>
#include <algorithm>
#include <utility>
#include <string.h>
#define mp std::make_pair

typedef std::pair<int, int> ip;

int a,b,c,m;
char str[10];

ip arr[300000];

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d",&m);
	int val;
	for(int i=0;i<m;i++) {
		scanf("%d %s", &val, str);
		arr[i].first=val;
		if(!strcmp(str, "USB"))
			arr[i].second=1;
		else
			arr[i].second=2;
	}

	std::sort(arr, arr+m);
	int cnt=0;
	long long res=0;
	for(int i=0;i<m;i++) {
		if(arr[i].second==1) {
			if(a) {
				a--; cnt++; res+=arr[i].first;
			}
			else if(c) {
				c--; cnt++; res+=arr[i].first;
			}
		}
		else {
			if(b) {
				b--; cnt++; res+=arr[i].first;
			}
			else if(c) {
				c--; cnt++; res+=arr[i].first;
			}	
		}
	}

	printf("%d %lld\n",cnt, res);

	return 0;
}