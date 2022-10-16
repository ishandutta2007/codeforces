#include<bits/stdc++.h>
using namespace std;
string s;
int n;
deque <char> k;
int main()
{
	cin>>n>>s;
	if(n%2)k.push_back(s[0]);
	for(int i=n%2;i<n;i+=2){
		k.push_front(s[i]);
		k.push_back(s[i+1]);
	}
	for(int i=0;i<k.size();i++)
		cout<<k[i];
	return 0;
}