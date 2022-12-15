#include <stdio.h>
#include <algorithm>

typedef long long lli;

lli ts, tf, t;
int n;
lli arr[100000];

int main()
{
	scanf("%lld %lld %lld", &ts, &tf, &t);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);
	std::sort(arr, arr+n);

	if(n==0) {
		printf("%lld\n",ts);
		return 0;
	}

	lli ti=arr[0]-1;
	if(ti>=tf) ti=tf-t;
	lli cnt=0;
	lli min=0;
	if(ti<ts) min=ts-ti+t;
	else min=t;
	for(int i=0;i<n;i++) {
		cnt++;
		if(i!=n-1 && arr[i]==arr[i+1]) continue;

		lli tmp=cnt*t;
		if(ts+tmp+t>tf) break;
		lli tt;
		if(i==n-1 || arr[i+1]>ts+tmp){
			tt=ts+tmp;
			if(min>t) {
				min=t;
				ti=tt;
			}
		}
		else{
			tt=arr[i+1]-1;

			lli ttt=ts+tmp-tt;
			if(min>ttt+t) {
				min=ttt+t;
				ti=tt;
			}
		}
	}

	printf("%lld\n",ti);
	return 0;
}