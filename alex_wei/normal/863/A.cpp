#include<bits/stdc++.h>
using namespace std;
int ans;
string x;
int main()
{
	cin>>x;
	ans=x.size();
	for(int i=ans;i>0;i--){
		if(x[i-1]=='0')ans--;
		else break;
	}
	for(int i=0;i<=ans/2;i++)
		if(x[i]!=x[ans-i-1])cout<<"NO",exit(0);
	cout<<"YES";
    return 0;
}