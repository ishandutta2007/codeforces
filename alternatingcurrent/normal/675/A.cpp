#include<bits/stdc++.h>
using namespace std;

void Judge(bool ok){
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(c == 0){
		Judge(a == b); 
	} else {
		if(c < 0) a = -a, b = -b, c = -c;
		if(a > b) cout << "NO\n";
		else{
			Judge(!((a - b) % c));
		}
	}
	return 0;
}