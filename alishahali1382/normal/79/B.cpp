#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int X[1010];
int n, m, k, t, r, c, tmp;
string fruit[3]={"Carrots", "Kiwis", "Grapes"};

int f(int a, int b){
	return (a-1)*m+b-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>k>>t;
	for (int i=0; i<k; i++){
		cin>>r>>c;
		X[i]=f(r, c);
	}
	sort(X, X+k);
	for (int i=0; i<t; i++){
		cin>>r>>c;
		tmp=f(r, c);
		auto it=lower_bound(X, X+k, tmp);
		if (*it==tmp){
			cout<<"Waste"<<endl;
			continue ;
		}
		cout<<fruit[(tmp-(it-X))%3]<<endl;
	}
	
	return 0;
}