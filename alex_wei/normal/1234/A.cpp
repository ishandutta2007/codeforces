#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n,a[105],s;
int main()
{
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n,s=0;
		for(int j=1;j<=n;j++)
			cin>>a[j],s+=a[j];
		if(s%n)s=s+n-s%n;
		cout<<s/n<<endl;
	}
	return 0;
}