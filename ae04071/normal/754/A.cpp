#include <stdio.h>
#include <cstring>

int arr[101];
int n;

int cache[101];
int next[101];

int DP(int idx)
{
	if(idx>=n) return 1;

	int &ret=cache[idx];
	if(ret!=-1) return ret;

	ret=0;
	int sum=0;
	for(int i=idx;i<n;i++) {
		sum+=arr[i];
		if(sum!=0) {
			if(DP(i+1)==1) {
				ret=1;
				next[idx]=i;
				break;
			}
		}
	}
	return ret;
}


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}

	memset(cache, -1, sizeof(cache));
	memset(next, -1, sizeof(next));
	DP(0);
	if(cache[0]==0)
		printf("NO\n");
	else {
		printf("YES\n");
		int idx=0;
		int cnt=0;
		while(idx<n) {
			int ri=next[idx];
			idx=ri+1;
			cnt++;
		}
		printf("%d\n",cnt);
		idx=0;
		while(idx<n) {
			int ri=next[idx];
			printf("%d %d\n", idx+1, ri+1);
			idx=ri+1;
		}
	}

	return 0;
}