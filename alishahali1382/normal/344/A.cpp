#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

ll n, ans=1;
char ch, tmp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	cin>>ch>>tmp;
	for (int i=1; i<n; i++){
		cin>>ch;
		if (ch==tmp){
			ans++;
		}
		cin>>tmp;
	}
	cout<<ans<<endl;
	return 0;
}