#include<bits/stdc++.h>
using namespace std;
int n,a[1005],ans;
vector <int> one; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])one.push_back(i);
	}
	for(int i=0;i<one.size();i++){
		ans++;
		if(i<one.size()-1&&one[i+1]-one[i]>1)ans++;
	}
	cout<<ans;
	return 0;
}