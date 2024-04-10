#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[33],pd[999];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		pd[a[i]]=1;
	}
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" ";
		int cnt=2;
		for(int j=1;j<=n*k&&cnt<=n;j++)
			if(!pd[j])
				cout<<j<<" ",cnt++,pd[j]=1;
		cout<<endl;
	}
	return 0;
}