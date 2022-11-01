#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

string s,t;
ll p[2],tmp;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]=='|')
    		tmp++;
    	else
			p[tmp]++;	
	}
	cin>>t;
	if(abs(p[0]-p[1])>t.size() || (t.size()-abs(p[0]-p[1]))&1)
		return cout<<"Impossible",0;
	
	ll l=(t.size()-(p[0]-p[1]))/2;
	int i=0,j=0;
	//cout<<l<<endl;
	while(s[i]!='|')
		cout<<s[i++];	
	for(;j<l;)
		cout<<t[j++];	
	while(i<s.size())
		cout<<s[i++];
	for(;j<t.size();)
		cout<<t[j++];			
		
		
    return 0;
}