#include<bits/stdc++.h>
using namespace std;
int T=1; 
int main(){
	cin>>T;
	while(T--){
		int n,a[53];
		cin>>n;
		bool ok=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=i)
				ok=0;
		}
		if(ok)
			cout<<0<<endl;
		else
			if(a[1]==1||a[n]==n)
				cout<<1<<endl;
			else
				if(a[1]==n&&a[n]==1)
					cout<<3<<endl;
				else
					cout<<2<<endl;
	}
}