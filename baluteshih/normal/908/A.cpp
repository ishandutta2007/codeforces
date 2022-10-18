#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int i,ans=0;
	for(i=0;i<s.size();i++)
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9') ans++;
	cout << ans << "\n";
}