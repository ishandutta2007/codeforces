#include<bits/stdc++.h>
using namespace std;
int cnt;
string s;
int main()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='0')cnt++;
		else if(cnt>5)cout<<"yes",exit(0);
	}
	cout<<"no";
    return 0;
}