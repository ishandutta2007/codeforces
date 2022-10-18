#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i;
	string s;
	char top='a';
	cin >> s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>top) break;
		if(s[i] == top) top++; 
	}
	printf("%s\n",i==s.size() ? "Yes" : "No");
}