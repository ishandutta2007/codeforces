#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

ll a, b, ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>a>>b;
	while (b){
		ans+=a/b;
		a=a%b;
		swap(a, b);
	}
	cout<<ans<<endl;
	
	return 0;
}