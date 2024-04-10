#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q,check[3][N],cnt,a,b;
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>a>>b;a--;
		check[a][b]=!check[a][b];
		if(check[a][b]){
			if(check[!a][b-1])cnt++;
			if(check[!a][b])cnt++;
			if(check[!a][b+1])cnt++;
		}
		else{
			if(check[!a][b-1])cnt--;
			if(check[!a][b])cnt--;
			if(check[!a][b+1])cnt--;
		}
		if(cnt)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}