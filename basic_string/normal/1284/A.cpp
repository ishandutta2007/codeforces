//%%%
#include<bits/stdc++.h>
using namespace std;
string a[22],b[22];
int main(){
	int n,m,q;
	cin>>n>>m;
	register int i;
	for(i=0;i<n;++i)cin>>a[i];
	for(i=0;i<m;++i)cin>>b[i];
	cin>>q;
	while(q--){
		cin>>i,--i;
		cout<<a[i%n]<<b[i%m]<<endl;
	}
	return 0;
}