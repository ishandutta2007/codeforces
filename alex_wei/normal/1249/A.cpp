#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n,a[105];
int main()
{
	cin>>q;
	while(q--){
		cin>>n;
		int pd=1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
			if(a[i-1]+1==a[i])
				pd=2;
		cout<<pd<<endl;
	}
    return 0;
}