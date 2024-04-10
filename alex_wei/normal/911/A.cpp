#include <bits/stdc++.h>
using namespace std;
int n,a[100005],m=1e9,s=-1,ans=1e5;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],m=min(m,a[i]);
	for(int i=0;i<n;i++)
		if(a[i]==m){
			if(s>-1)ans=min(ans,i-s);
			s=i;
		}
	cout<<ans;
    return 0;
}