#include<bits/stdc++.h>
using namespace std;
vector<int>a;
void out(){
	bool b=0;
	for(int i:a){
		if(b)cout<<'.';cout<<i;
		
		b=1;
	}
	cout<<'\n';
}
int main(){
	int n,i,j,k,T;
	ios::sync_with_stdio(0),cin>>T;
	while(T--){
		cin>>n>>i;
		a.clear();
		a.push_back(1);
		out();
		for(i=2;i<=n;++i){
			cin>>j;
			if(j==1)a.push_back(1);
			else{
				while(j!=a.back()+1)a.pop_back();
				a.back()=j;
			}
			out();
		}
	}
	return 0;
}