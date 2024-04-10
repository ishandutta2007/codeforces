#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[1005];
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			if(a[i]>=n-i+1){
				cout<<n-i+1<<endl;
				break;
			}
	}
    return 0;
}