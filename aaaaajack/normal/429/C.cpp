#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int a[30],b[30],lf=0,in=0;
bool check(int now){
	if(now==in){
		int cnt=0;
		for(int i=0;i<in;i++) cnt+=b[i];
		if(cnt==lf) return true;
		return false;
	}
	for(int i=0;i<now;i++){
		if(a[now]<a[i]-1&&a[now]<=b[i]){
			b[i]-=a[now];
			if(check(now+1)) return true;
			b[i]+=a[now];
		}
	}
	return false;
}	
int main(){
	int n,i;
	bool flag=true;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	for(i=0;i<n;i++){
		b[i]=a[i]-1;
		if(a[i]>2) in++;
		else if(a[i]==2) flag=false;
		else lf++;
	}
	if(lf<=in||a[0]!=n) flag=false;
	if(flag&&(n==1||check(1))) printf("YES\n");
	else printf("NO\n");
	return 0;
}