#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,n,m,ans,p1,now,rot,num;
int main()
{
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n>>m,now=m,num=1;
		ans=0;
		if(n<m){cout<<"0\n";continue;}
		n-=n%m;
		p1=(m+m)%10,rot=m%10;
		while(p1!=m%10)rot+=p1,p1=(p1+m)%10,num++;
		p1=m%10;
		while(p1!=n%10)ans+=p1,p1=(p1+m)%10,now+=m;
		ans+=p1;
		cout<<ans+(n-now)/m/num*rot<<endl;
	}
    return 0;
}