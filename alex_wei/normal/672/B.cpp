#include<bits/stdc++.h>
using namespace std;
string s; int n,buc[26],ans;
int main(){
	cin>>n>>s;
	if(s.size()>26)puts("-1"),exit(0);
	for(int i=0;i<s.size();i++){
		ans+=buc[s[i]-'a'];
		buc[s[i]-'a']=1;
	}
	cout<<ans<<endl;
    return 0;
}