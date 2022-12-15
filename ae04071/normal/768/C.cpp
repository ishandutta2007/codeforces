#include <stdio.h>
#include <algorithm>
int n,k,x,arr[1<<10], tmp[1<<10];
int main(){
	scanf("%d %d %d",&n,&k,&x);
	int val;
	for(int i=0;i<n;i++){
		scanf("%d",&val);
		arr[val]++;
	}

	for(int t=0;t<k;t++) {
		for(int i=0;i<(1<<10);i++)
			tmp[i]=arr[i];
		int prev=0;
		for(int j=0;j<(1<<10);j++) {
			if(arr[j]==0) continue;

			int ch_cnt=arr[j]/2, ch_val=j^x;
			if(prev==0) ch_cnt+=(arr[j]&1);

			tmp[j]-=ch_cnt;
			tmp[ch_val]+=ch_cnt;
			prev^=(arr[j]&1);
		}


		for(int j=0;j<(1<<10);j++) 
			arr[j]=tmp[j];
	}

	int min=(1<<10)+1, max=-1;
	for(int i=0;i<(1<<10);i++) {
		if(arr[i]>0) {
			if(max<i) max=i;
			if(min>i) min=i;
		}
	}

	printf("%d %d\n",max, min);


	return 0;
}