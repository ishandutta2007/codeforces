#include<bits/stdc++.h>
using namespace std;
vector <char> k;
int n;
int vow(char s){return s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='y';}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		char p;
		cin>>p;
		k.push_back(p);
	}
	for(int i=0;i<k.size()-1;i++)
		if(vow(k[i])&&vow(k[i+1]))
			k.erase(k.begin()+i+1),i--;
	for(int i=0;i<k.size();i++)
		cout<<k[i];
	return 0;
}