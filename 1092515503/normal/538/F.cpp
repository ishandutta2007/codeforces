#include<bits/stdc++.h>
using namespace std;
int n,a[200100],d[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		int j=i-2;
		if(a[1]>a[i])d[j+1]++;
		for(int l=1,r;l<=j;l=r+1){
			r=j/(j/l);
			int k=(j/l)+1;
			if(a[k]>a[i])d[l]++,d[r+1]--;
		}
	}
	for(int i=1;i<n;i++)d[i]+=d[i-1],printf("%d ",d[i]);
	return 0;
}