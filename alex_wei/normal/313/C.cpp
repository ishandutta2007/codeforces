#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s,ans,a[2000006],pd[2000006];
bool cmp(int a,int b){return a>b;}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int c=1;while(c<=n)pd[c]=1,c*=4;
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(pd[i])ans+=s;
	}
	cout<<ans;
	return 0;
}