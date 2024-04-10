#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,b;
string s;
vector <int> ans;
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='B')b++;
	if(s.size()%2==0&&b%2)puts("-1"),exit(0);
	for(int i=1;i<n-1;i++)
		if(s[i-1]!=s[i]){
			ans.push_back(i+1),s[i]=(s[i]=='B'?'W':'B');
			s[i+1]=(s[i+1]=='B'?'W':'B');
		}
	for(int i=0;i<n;i++)
		if(s.size()%2==0&&s[i]=='W')
			ans.push_back(i+1),i++;
		else if(s.size()%2&&b%2&&s[i]=='W')ans.push_back(i+1),i++;
		else if(s.size()%2&&b%2==0&&s[i]=='B')ans.push_back(i+1),i++;
	cout<<ans.size()<<endl;
	for(int i=1;i<=ans.size();i++)
		cout<<ans[i-1]<<" "; 
    return 0;
}