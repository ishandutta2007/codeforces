#include<bits/stdc++.h>
#define ll long long
#define N
using namespace std;
int n,a[5];
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		int ans = 0;
		sort(a+1,a+4,cmp);
		if(a[1]>0) a[1]--,ans++;
		if(a[2]>0) a[2]--,ans++;
		if(a[3]>0) a[3]--,ans++;
		if(a[1]>0&&a[2]>0) a[1]--,a[2]--,ans++;
		if(a[1]>0&&a[3]>0) a[1]--,a[3]--,ans++;
		if(a[3]>0&&a[2]>0) a[3]--,a[2]--,ans++;
		if(a[1]>0&&a[2]>0&&a[3]>0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}