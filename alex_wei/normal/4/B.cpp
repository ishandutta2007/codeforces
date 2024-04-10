#include <bits/stdc++.h>
using namespace std;
int st,mit,mat,n,a[32],b[32];
int main()
{
	cin>>n>>st;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i],mit+=a[i],mat+=b[i];
	if(st<mit||mat<st)cout<<"NO",exit(0);
	st-=mit;
	cout<<"YES\n"; 
	for(int i=0;i<n;i++){
		int more=min(b[i]-a[i],st);
		st-=more;
		cout<<more+a[i]<<" ";
	}
    return 0;
}