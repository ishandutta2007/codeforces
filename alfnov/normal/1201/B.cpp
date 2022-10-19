#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int suan(int l,int r){
	int k=0;
	for(int i=l;i<=r;++i)b[++k]=a[i];
	sort(b+1,b+k+1);
	long long he=b[1],cl=b[1];
	for(int i=2;i<=k;++i){
		long long cs=(he-cl)/2;
		he+=b[i];
		b[i]-=cl;
		b[i]-=2*min(0ll+b[i]/2,cs);
		cl=b[i];
	}
	return (cl==0);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(suan(1,n))puts("YES");
	else puts("NO");
	return 0;
}