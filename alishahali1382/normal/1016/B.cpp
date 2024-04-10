#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, q, l, r, ans[1001][1001];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>q;
	getline(cin, s);
	getline(cin, s);
	getline(cin, t);
	for (int i=0; i<n; i++){
		ans[i][i]=(m==1 & t[0]==s[i]);
		for (int j=i+m-1; j<n; j++){
			ans[i][j]=ans[i][j-1] + (t==s.substr(j-m+1, m));
			
		}
	}
	for (int i=0; i<q; i++){
		cin>>l>>r;
		cout<<ans[l-1][r-1]<<endl;
		//cout<<s.substr(l-1, r)<<endl;
	}
	return 0;
}