#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;

int x=1, ans;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	getline(cin, s);
	int n=s.size();
	s=s+s; //!!!!
	
	for (int i=1; i<2*n; i++){
		if (s[i]!=s[i-1]){
			ans=max(ans, ++x);
		}
		else{
			x=1;
		}
	}
	cout<<max(min(n, ans), 1)<<endl;
	
	return 0;
}