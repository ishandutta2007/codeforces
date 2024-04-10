#include<bits/stdc++.h>
using namespace std;
string s;
map <string,int> c;
int main()
{
	cin>>s;
	for(int i=0;i<10;i++){
		string k;
		cin>>k,c[k]=i;
	}
	for(int i=0;i<8;i++)
		cout<<c[s.substr(i*10,10)];
	return 0; 
}