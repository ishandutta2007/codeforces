#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
	string tmp;
	int n;
	scanf("%d",&n);
	while(n--){
		cin>>tmp;
		if(s.count(tmp)) cout<<"YES"<<endl;
		else{
			s.insert(tmp);
			cout<<"NO"<<endl;
		}
	}
	return 0;
}