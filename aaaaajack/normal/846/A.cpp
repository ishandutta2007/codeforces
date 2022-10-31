#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int ans=10000;
	int a[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n;i++){
		int cnt=0;
		for(int j=0;j<i;j++){
			if(a[j]==1) cnt++;
		}
		for(int j=i;j<n;j++){
			if(a[j]==0) cnt++;
		}
		if(cnt<ans) ans=cnt;
	}
	printf("%d\n",n-ans);
	return 0;
}