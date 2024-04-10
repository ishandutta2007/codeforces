#include<bits/stdc++.h>
using namespace std;
string s;
int c[129];
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)c[s[i]]++;
	cout<<min(min(min(c['B'],c['u']/2),c['l']),min(min(c['b'],c['a']/2),min(c['s'],c['r'])));
	return 0;
}