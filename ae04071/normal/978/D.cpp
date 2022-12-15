#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int n;
lli arr[100000],a[100000];

lli _abs(lli a) {
	return a<0 ? -a : a;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);

	if(n<=2) {
		puts("0");
		return 0;
	}

	int mx=1e9;
	for(int i=0;i<9;i++) {
		for(int i=0;i<n;i++) a[i]=arr[i];

		int cnt=0;
		if(i%3==1) a[0]++,cnt++;
		else if(i%3==2) a[0]--,cnt++;
		if(i/3==1) a[1]++,cnt++;
		else if(i/3==2) a[1]--,cnt++;

		lli dif=a[1]-a[0];
		int f=1;
		for(int i=2;i<n;i++) {
			lli d=a[i]-a[i-1];
			if(d!=dif) {
				if(_abs(dif-d)>1){
					f=0;
					break;
				}
				else if(dif-d==1) {
					a[i]++; cnt++;
				}
				else if(dif-d==-1) {
					a[i]--;cnt++;
				}
			}
		}
		if(f) mx=min(mx,cnt);
	}
	if(mx==1000000000) puts("-1");
	else printf("%d\n",mx);
	
	return 0;
}