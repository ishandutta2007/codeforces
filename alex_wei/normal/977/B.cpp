#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s,k;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n-1;i++){
		string t=s.substr(i,2);
		int cnt=0,p=0;
		while(s.find(t,p)!=-1)cnt++,p=s.find(t,p)+1;
		if(cnt>ans)ans=cnt,k=t;
	}
	cout<<k;
    return 0;
}