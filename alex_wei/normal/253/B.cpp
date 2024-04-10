#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c[200005],ans;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)ans=max(ans,upper_bound(c+1,c+n+1,c[i]*2)-c-i);
	cout<<n-ans;
    return 0;
}