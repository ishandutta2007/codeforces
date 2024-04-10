#include <cstdio>

int n=5;
int arr[5][5];
int max=0;
int t[5];

void Check() {
	int sum=0;
	for(int i=0;i<n;i++) {
		for(int j=i;j+1<n;j+=2) {
			sum+=arr[t[j]][t[j+1]]+arr[t[j+1]][t[j]];
		}
	}
	if(max<sum) max=sum;
}
void make(int idx) {
	if(idx==5) {
		Check();
		return;
	}
	int use=0;
	for(int i=0;i<idx;i++) {
		use|=(1<<t[i]);
	}
	for(int i=0;i<n;i++) if(!(use&(1<<i))) {
		t[idx]=i;
		make(idx+1);
	}
}
int main() {
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	make(0);
	printf("%d\n",max);
	
	return 0;
}