#include <bits/stdc++.h>
using namespace std;
map <string,int> k;
int n;
string s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(k[s])cout<<s<<k[s]<<endl;
		else cout<<"OK\n";
		k[s]++;
	}
    return 0;
}