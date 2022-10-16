#include<bits/stdc++.h>
using namespace std;
int n,a[102],s,sum,ans; 
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		if(i==0||a[i]*2<=a[0])
			s+=a[i],ans++;
	}
	if(s*2>sum){
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			if(i==0||a[i]*2<=a[0])
				cout<<i+1<<" ";
	}
	else cout<<"0";
	return 0;
}