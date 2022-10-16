#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,a[N],ans,tmp=2;
int main(){
	cin>>n;
	if(n<=2)printf("%d\n",n),exit(0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		if(a[i]!=a[i-1]+a[i-2])ans=max(ans,tmp),tmp=2;
		else tmp++;
	}
	cout<<max(ans,tmp)<<endl;
    return 0;
}