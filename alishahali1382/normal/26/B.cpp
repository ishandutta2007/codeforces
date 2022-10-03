#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;

int n, ans, x;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	getline(cin, s);
	n=s.size();
	for (int i=0; i<n; i++){
		if (s[i]==')'){
			if (x>0) ans++;
			x=max(0, x-1);
		}
		else{
			x++;
		}
	}
	cout<<ans*2<<endl;
	
	return 0;
}