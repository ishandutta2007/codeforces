#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=s.size(),cnt=0;
		for(int i=0;i<n;++i)
		if(s[i]=='0'&&(i==0||s[i-1]!='0')){
			++cnt;
		}
		cout<<min(2,cnt)<<endl;
	}
}