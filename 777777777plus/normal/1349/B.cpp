#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,k;
int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		bool flag=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==k)flag=1;
		}
		if(!flag){
			puts("no");
			continue;
		}
		else if(n==1){
			puts("yes");
			continue;
		} 
		flag=0;
		for(int i=1;i<n;++i)
		if(a[i]>=k&&a[i+1]>=k){
			flag=1;
		}
		for(int i=1;i<n-1;++i)
		if(a[i]>=k&&a[i+2]>=k){
			flag=1;
		}
		if(flag)puts("yes");
		else puts("no");
	}
}