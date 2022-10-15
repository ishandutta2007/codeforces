#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin>>n;
	while (n--){
		string s; cin>>s;
		char c = s[s.length()-1];
		if (c=='o')
			cout<<"FILIPINO"<<endl;
		if (c=='u')
			cout<<"JAPANESE"<<endl;
		if (c=='a')
			cout<<"KOREAN"<<endl;
	}
}