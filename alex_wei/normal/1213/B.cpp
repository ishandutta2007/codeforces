#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[150002];
int main()
{
	cin>>t;
	for(int l=1;l<=t;l++){
		int num=0,mi=1e9;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>0;i--){
			if(a[i]>mi)num++;
			mi=min(mi,a[i]);
		}
		cout<<num<<endl;
	}
    return 0;
}