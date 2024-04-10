#include<bits/stdc++.h>
using namespace std;
set<int>st;
enum{N=10009};
int a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,fi,mn,mx,ans;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)st.insert(i);
		while(st.size()){
			i=*st.begin();
			cout<<"? "<<i<<endl;
			cin>>fi;j=fi;
			while(cout<<"? "<<i<<endl,cin>>k,1){
				a[j]=k;j=k;st.erase(j);
				if(k==fi)break; 
			}
		}cout<<"! ";
		for(i=1;i<=n;++i)cout<<a[i]<<' ';cout<<endl;
	}
	return 0;
}