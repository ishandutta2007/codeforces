#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,p[100005],q[100005];
int main()
{
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n;
		ll odd1=0,odd2=0,eve1=0,eve2=0;
		for(int i=1;i<=n;i++)
			cin>>p[i],p[i]%2?odd1++:eve1++;
		cin>>m;
		for(int i=1;i<=m;i++)
			cin>>q[i],q[i]%2?odd2++:eve2++;
		cout<<odd1*odd2+eve1*eve2<<endl;
	}
    return 0;
}