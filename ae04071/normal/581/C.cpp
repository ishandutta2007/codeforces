#include <bits/stdc++.h>
using namespace std;

int n,k,a[100000];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	sort(a,a+n,[](const int &a,const int &b) {
		return a%10 > b%10;
	});

	for(int i=0;i<n && k;i++) {
		if(a[i]==100) continue;
		if(10-(a[i]%10)<=k) {
			int t=10-(a[i]%10);
			k-=t; a[i]+=t;
		} else {
			k=0;
			break;
		}
	}

	for(int i=0;i<n;i++) 
		a[i]/=10;
	k/=10;
	for(int i=0;i<n && k;i++) if(a[i] < 10) {
		int t=10-a[i];
		if(t<=k) {
			a[i]+=t; k-=t;
		} else {
			a[i]+=k; k=0; break;
		}
	}

	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];

	printf("%d\n",sum);

	return 0;
}