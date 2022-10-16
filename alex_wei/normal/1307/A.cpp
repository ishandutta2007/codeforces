#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int t,n,d,a[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=a[1];
		for(int i=2;i<=n;i++){
			int rem=d/(i-1);
			int cal=min(rem,a[i]);
			d-=cal*(i-1),ans+=cal;
		}
		cout<<ans<<endl;
	}
    return 0;
}