#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s; cin>>s;
	string xd="heidi";
	int pos=0;
	for(auto z:s)
	{
		if(z==xd[pos])++pos;
		if(pos==xd.size()){ puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}