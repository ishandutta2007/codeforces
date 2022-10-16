#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,q,c[200005],a[200005];
int main()
{
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		c[l]++,c[r+1]--;
	}
	for(int i=1;i<=200000;i++){
		c[i]+=c[i-1],a[i]=a[i-1]+(c[i]>=k);
//		if(i<101&&i>89)cout<<c[i]<<" "<<a[i]<<endl;
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<a[r]-a[l-1]<<endl;
	}
	return 0;
}