#include<bits/stdc++.h>
using namespace std;
char c,las='a';
int num; 
int main()
{
	while(cin>>c){
		if(!isalpha(c))break;
		num+=min(abs(c-las),min(abs(las+26-c),abs(c+26-las)));
		las=c;
	}
	cout<<num<<endl;
	return 0;
}