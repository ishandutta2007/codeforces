#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

int n;
string s;

map<string, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>s;
		if (mp[s]){
			cout<<s<<mp[s]++<<endl;
		}
		else {
			mp[s]=1;
			cout<<"OK"<<endl;
		}
	}
	
	return 0;
}