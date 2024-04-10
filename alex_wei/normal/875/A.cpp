#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> ans;
int main()
{
	cin>>n;
	for(int i=n-1;i>=n-1000;i--){
		int r=i,c=0;
		while(r)c+=r%10,r/=10;
		if(i+c==n)ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<" ";
	return 0;
}