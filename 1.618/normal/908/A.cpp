#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
string s;
int ans;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			if((s[i]-'0')&1) ans++;
		}else{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}