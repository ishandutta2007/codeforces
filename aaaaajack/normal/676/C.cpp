#include<bits/stdc++.h>
#define N 100100
using namespace std;
char s[N];
int la[N],lb[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		la[i]=la[i-1]+(s[i]=='a');
		lb[i]=lb[i-1]+(s[i]=='b');
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,upper_bound(la+1,la+n+1,la[i-1]+k)-la-i);
		ans=max(ans,upper_bound(lb+1,lb+n+1,lb[i-1]+k)-lb-i);
	}
	printf("%d\n",ans);
	return 0;
}