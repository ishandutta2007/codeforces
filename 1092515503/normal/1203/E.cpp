#include<bits/stdc++.h>
using namespace std;
int n,a[150001],las,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(las>a[i])continue;
		if(las<a[i]-1){
			las=a[i]-1,cnt++;
			continue;
		}
		if(las<a[i]){
			las=a[i],cnt++;
			continue;
		}
		if(las<a[i]+1){
			las=a[i]+1,cnt++;
			continue;
		}
	}
	printf("%d\n",cnt);
	return 0;
}