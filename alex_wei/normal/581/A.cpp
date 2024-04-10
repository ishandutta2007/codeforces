#include<bits/stdc++.h>
using namespace std;
int a,b; 
int main()
{
	cin>>a>>b;
	int ans=min(a,b);
	cout<<ans<<" "<<max((a-ans)/2,(b-ans)/2);
	return 0;
}