#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n!=2 && !(n%2)){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	
	return 0;
}