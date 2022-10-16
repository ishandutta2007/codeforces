#include<bits/stdc++.h>
using namespace std;
int k[128];
string a,b; 
int main()
{
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.size();i++)
		if(a[i]!=' ')k[a[i]]++;
	for(int i=0;i<b.size();i++)
		if(b[i]!=' '){if(!k[b[i]])cout<<"NO",exit(0);k[b[i]]--;}
	cout<<"YES";
	return 0;
}