#include<bits/stdc++.h>
using namespace std;
map <string,bool> k;
int n;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s,k[s]=1;
	cout<<6-n<<endl;
	if(!k["purple"])cout<<"Power\n";
	if(!k["green"])cout<<"Time\n";
	if(!k["blue"])cout<<"Space\n";
	if(!k["orange"])cout<<"Soul\n";
	if(!k["red"])cout<<"Reality\n";
	if(!k["yellow"])cout<<"Mind\n";
    return 0;
}