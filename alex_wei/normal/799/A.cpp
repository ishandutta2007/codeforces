#include<bits/stdc++.h>
using namespace std;
int n,t,k,d,a,b,bk; 
int main()
{
	cin>>n>>t>>k>>d;
	a=((n-1)/k+1)*t;
	b=d;
	bk=(d/t)*k;
	while(bk<n){
		if(bk+k>=n)b=b-d%t+t,bk+=k;
		else b+=t,bk+=k*2;
	}
//	cout<<a<<" "<<b<<" "<<endl;
	if(a<=b)cout<<"NO";
	else cout<<"YES";
	return 0;
}