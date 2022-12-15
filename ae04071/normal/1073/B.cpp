#include <bits/stdc++.h>
using namespace std;

int n,a[200000],b[200000],vis[200001];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
		scanf("%d",a+i);

	int i=0;
	for(int j=0;j<n;j++) {
		scanf("%d",b+j);
		if(vis[b[j]]){
			printf("0 ");
		} else {
			int cnt=0;
			for(;i<n && a[i]!=b[j];i++) {
				vis[a[i]]=1;cnt++;
			}
			cnt++; vis[a[i++]]=1;
			printf("%d ",cnt);
		}
	}

	return 0;
}