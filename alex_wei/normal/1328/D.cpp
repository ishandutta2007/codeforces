#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int q,n,t[N],c[N]; 
int main(){
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>t[i];
		bool s=0;
		for(int i=2;i<=n;i++)if(t[i]!=t[i-1])s=1;
		if(s==0){
			cout<<"1\n";
			for(int i=1;i<=n;i++)cout<<1<<" ";
		}
		else{
			if(n%2==0||t[1]==t[n]){
				cout<<"2\n";
				for(int i=1;i<=n;i++)cout<<((i&1)+1)<<" ";
			}
			else{
				bool tag=0;
				for(int i=2;i<=n;i++)if(t[i]==t[i-1]){
					cout<<"2\n";
					for(int j=1;j<=i-1;j++)cout<<((j&1)+1)<<" ";
					for(int j=i;j<=n;j++)cout<<(((j-1)&1)+1)<<" ";
					tag=1;
					break;
				}
				if(!tag){
					cout<<"3\n";
					for(int i=1;i<=n;i++)cout<<(i<n?(i&1)+1:3)<<" ";
				}
			}
		}
		puts("");
	}
	
	return 0;
}