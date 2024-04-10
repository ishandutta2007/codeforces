#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a,ans;
map <int,int> z;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		z.clear();
		for(int i=1;i<=n;i++){
			cin>>a;
			int cnt=0;
			while(a%2==0)ans+=!z[a],z[a]=1,a/=2;
		}
		cout<<ans<<endl;
		ans=0;
	}
    return 0;
}