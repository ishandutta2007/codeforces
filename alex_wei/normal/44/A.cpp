#include<bits/stdc++.h>
using namespace std;
map <string,int> k;
int n,ans;
string s;
int main()
{
	cin>>n;
	getline(cin,s);
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(!k[s])ans++;
		k[s]++;
	}
	cout<<ans;
    return 0;
}