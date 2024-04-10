#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l;
	for(cin>>T;T--;){
		cin>>n;
		map<int,int>mp;
		int s=0;
		while(n--){
			cin>>i;
			if(mp[abs(i)])mp[-abs(i)]=1;
			else mp[abs(i)]=1;
		}
		cout<<mp.size()<<'\n';
	}
	return 0;
}