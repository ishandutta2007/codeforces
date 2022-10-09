#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[1002][1002];

int getdrop(int x){
	int i=1, j=x;
	while(i<=n){
		if(a[i][j]==2) i++;
		else if(a[i][j]==1) a[i][j]=2, j++;
		else a[i][j]=2, j--;
	}
	return j;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	while(k--){
		int x;
		cin>>x;
		cout<<getdrop(x)<<" ";
	}
	cout<<"\n";
	return 0;
}