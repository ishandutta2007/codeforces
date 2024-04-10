#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,c,m,x;
int main()
{
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>c>>m>>x;//A,B,C
		int ans=min(c,min(m,x));// C 
		c-=ans,m-=ans;//
		if(c*2<=m)cout<<ans+c<<endl;// 
		else if(m*2<=c)cout<<ans+m<<endl;//
		else cout<<ans+(c+m)/3<<endl;//
	}
    return 0;
}