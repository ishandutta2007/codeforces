#include<bits/stdc++.h>
using namespace std;
int a[2009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m;
		if(n>m){
			cout<<"No\n";
			continue;
		}
		if(n%2==1){cout<<"Yes\n";
			cout<<m-n+1<<' ';
			while(--n)cout<<1<<' ';cout<<'\n';
		}else{
			if(m%2==1){
				cout<<"No\n";
			}else{
				cout<<"Yes\n";
				m-=n-2;m/=2;
				cout<<m<<' '<<m<<' ';
				n-=2;
				while(n--)cout<<1<<' ';cout<<'\n';
			}
		}
	}
}