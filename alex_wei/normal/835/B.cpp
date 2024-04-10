#include<bits/stdc++.h>
using namespace std;
int k,sum,j[10],cnt,p;
string s;
int main()
{
	cin>>k>>s;
	for(int i=0;i<s.size();i++)
		sum+=s[i]-'0',j[s[i]-'0']++;
	while(sum<k){
		while(!j[p])p++;
		sum+=9-p,j[p]--;
		cnt++;
	}
	cout<<cnt;
	return 0;
}