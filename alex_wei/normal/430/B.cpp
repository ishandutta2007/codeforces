#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,x,a[102],ans;
int solve(int pos)
{
	int r[102],num=n+1;
	for(int i=1;i<=pos;i++)
		r[i]=a[i];
	r[pos+1]=x;
	for(int i=pos+1;i<=n;i++)
		r[i+1]=a[i];
//	for(int i=1;i<=n+1;i++)
//		cout<<r[i]<<" ";
//	cout<<endl;
	while(num>=3){
		int op=0;
		for(int i=1;i<num-1;)
			if(r[i]==r[i+1]&&r[i+1]==r[i+2]){
				op=1;
				int pos2=i;
				while(pos2<=num&&r[pos2]==r[i])pos2++;
				num-=pos2-i;
				for(int j=i;j<=num;j++)
					r[j]=r[j+pos2-i];
			}
			else i++;
		if(!op)break;
	}
	return n-num;
}
int main()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		ans=max(ans,solve(i));
	cout<<ans;
	return 0;
}