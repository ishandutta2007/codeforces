#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int main(){
	cin>>n>>m>>k;
	int len=n+m-2+n*m-1;
	cout<<len<<endl;
	for(int i=1;i<m;i++)cout<<"R";
	for(int i=1;i<n;i++)cout<<"D";
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)if(i&1)cout<<"L"; else cout<<"R";
		if(i<n)cout<<"U";
	}
	return 0;
}