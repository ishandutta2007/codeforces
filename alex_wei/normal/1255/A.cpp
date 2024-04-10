#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,a,b; 
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a<b)swap(a,b);
		int cha=a-b;
		int ans=cha/5;
		cha%=5;
		ans+=cha/2;
		cha%=2;
		ans+=cha;
		cout<<ans<<endl;
	}
    return 0;
}