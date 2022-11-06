#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans=0;
	string s;
	cin >> n >> m >> s;
	rep(i,1,n)
		if(s[i] == '.' && s[i-1] == '.')
			++ans;
	rep(i,0,m){
		int x;
		char c;
		cin >> x >> c;
		if((s[x] == '.') && (s[x-1] == '.'))
			--ans;
		if((s[x-1] == '.') && (s[x-2] == '.'))
			--ans;
		s[x-1] = c;
		if((s[x] == '.') && (s[x-1] == '.'))
			++ans;
		if((s[x-1] == '.') && (s[x-2] == '.'))
			++ans;
		cout << ans << endl;
	}
}