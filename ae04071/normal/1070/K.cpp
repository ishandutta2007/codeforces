#include <bits/stdc++.h>
using namespace std;

int n,k,a[100000];
int main() {
	int sum=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),sum+=a[i];

	if(sum%k!=0) {
		puts("No");
		return 0;
	}

	vector<int> ans;
	int t=0;
	for(int i=0,j;i<n;i=j) {
		t=0;
		for(j=i;j<n && t<sum/k;j++)
			t+=a[j];
		if(t!=sum/k) {
			puts("No");
			return 0;
		}
		ans.push_back(j-i);
	}
	printf("Yes\n");
	for(auto &it:ans)
		printf("%d ",it);

	return 0;
}