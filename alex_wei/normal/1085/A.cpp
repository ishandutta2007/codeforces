#include<bits/stdc++.h>
using namespace std;
string s,t;
deque <char> p;
int main()
{
	cin>>t;
	for(int i=0;i<t.size();i++)
		p.push_back(t[i]);
	while(!p.empty()){
		if(p.size()%2)s+=p.front(),p.pop_front();
		else s+=p.back(),p.pop_back();
	}
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
}