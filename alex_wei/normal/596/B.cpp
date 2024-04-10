#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll b[N],n,ans; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i],ans+=abs(b[i]-b[i-1]);
	cout<<ans<<endl;
	return 0;
}