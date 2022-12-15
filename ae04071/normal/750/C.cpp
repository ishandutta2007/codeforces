#include <stdio.h>
#include <algorithm>

const int INF=21000000;

int n;
int c[200000], d[200000];
int res=-INF;

int Check(int rate)
{
	for(int i=0;i<n;i++) {
		if(d[i]==1) {
			if(rate<1900) {
				return 1;
			}
			rate+=c[i];
		}
		else {
			if(rate>=1900) return -1;
			rate+=c[i];
		}
	}
	res=std::max(res,rate);
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d",c+i,d+i);
	}

	int min=-INF, max=INF;
	while(max-min>1) {
		int mid=(min+max)/2;
		int chk=Check(mid);
		if(chk<0) {
			max=mid;
		}
		else {
			min=mid;
		}
	}
	if(res==-INF) printf("Impossible\n");
	else {
		if(max==INF || min==INF) printf("Infinity\n");
		else printf("%d\n",res);
	}

	return 0;
}