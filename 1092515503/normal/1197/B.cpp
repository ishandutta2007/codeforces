#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
bool aft,ans=true;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!aft&&a[i]<a[i-1])ans=false;
		if(aft&&a[i]>a[i-1])ans=false;
		if(a[i]==n)aft=true;
	}
	puts(ans?"YES":"NO");
	return 0;
}