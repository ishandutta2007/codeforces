#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll n,a,b;

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>n;
		int ans=0;
		while(max(a,b)<=n){
			if(a>b)swap(a,b);
			a+=b;
			ans++;
		}
		printf("%d\n",ans);
	}
}