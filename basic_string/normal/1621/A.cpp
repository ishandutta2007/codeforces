#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>k;
		if(k*2-1<=n){
			for(i=1;i<=n;++i){
				for(j=1;j<=n;++j){
					if(i%2==1&&(i+1)/2<=k&&i==j)cout<<'R';
					else cout<<'.';
				}cout<<'\n';
			}
		}
		else{
			cout<<"-1\n";
		}
	}
	return 0;
}