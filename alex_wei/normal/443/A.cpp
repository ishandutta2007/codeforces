#include<bits/stdc++.h>
using namespace std;
int k[128],ans;
char s; 
int main()
{
	cin>>s;
	while(s!='}'){
		cin>>s;
		if(s=='}')break;
		ans+=!k[s],k[s]=1,cin>>s;
	}
	cout<<ans;
	return 0;
}