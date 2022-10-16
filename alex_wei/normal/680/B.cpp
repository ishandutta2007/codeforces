#include<bits/stdc++.h>
using namespace std;
int n,a,t[105],ans; 
int main()
{
	cin>>n>>a;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=0;i<=n;i++){
		int l=a-i,r=a+i;
		if(!i)ans+=t[l];
		else if(l>0&&r<=n){
			if(t[l]&&t[r])ans+=2;
		}
		else if(l>0&&r>n)ans+=t[l];
		else if(l<=0&&r<=n)ans+=t[r];
	}
	cout<<ans;
	return 0;
}