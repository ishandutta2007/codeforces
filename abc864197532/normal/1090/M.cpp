#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,k;
	cin>>n>>k;
	int x[n];
	int cnt=1,ans=1;
	for(int i=0;i<n;i++){
		cin>>x[i];
		if(!i) continue; 
		if(x[i]==x[i-1]) cnt=1;
		else cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
}