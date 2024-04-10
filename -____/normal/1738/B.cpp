#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
int n,k,a[N],s[N];
int main(){
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++)
			scanf("%d",s+i);
		for(i=2;i<=k;i++)
			a[i]=s[i]-s[i-1];
		x=0;
		for(i=3;i<=k;i++)
			if(a[i-1]>a[i])
				x=1;
		if(k==1)
			a[2]=2e9;
		n-=k-1;
		if(x||(long long)n*a[2]<s[1])
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}