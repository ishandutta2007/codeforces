#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a=1,b=n-1;
		for(int i=2;i<=sqrt(n);i++)
			if(n%i==0){
				a=n/i,b=n-a;
				break;
			}
		cout<<a<<' '<<b<<'\n';
	}
}