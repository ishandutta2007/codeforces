#include<bits/stdc++.h>
using namespace std;
int t,n,k,a,p[202];
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		int s=0;
		memset(p,0x3f,sizeof(p));
		for(int j=0;j<k;j++){
			cin>>a;
			for(int l=1;l<=n;l++)
				p[l]=min(p[l],abs(a-l)+1);
		}
		for(int j=1;j<=n;j++)
			s=max(s,p[j]);
		cout<<s<<endl;
	}
	return 0;
}