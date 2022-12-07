#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		if(k==0){
			for(int i=0;i<n/2;i++)
				cout<<i<<' '<<n-1-i<<endl;
			continue;
		}
		if(n==4&&k==3){
			cout<<-1<<endl;
			continue;
		}
		if(n==k+1){
			cout<<0<<' '<<n/2<<endl;
			cout<<1<<' '<<n/2-1<<endl;
			cout<<n-1<<' '<<n-2<<endl;
			for(int i=2;i<n/2-1;i++)
				cout<<i<<' '<<n-1-i<<endl;
			continue;
		}
		for(int i=0;i<n/2;i++){
			int a=i,b=n-1-i;
			if(a==0)
				cout<<0<<' '<<n-1-k<<endl;
			else
				if(a==k)
					cout<<n-1<<' '<<k<<endl;
				else
					if(b==k)
						cout<<n-1<<' '<<k<<endl;
					else
						cout<<a<<' '<<b<<endl;
		}
	}
}