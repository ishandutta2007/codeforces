#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	s+=s;
	int ans=0,l=0;
	for (int i=0;i<s.size();i++)
	{
		if (i && s[i]==s[i-1])
		l=i;
		ans=max(ans,i-l+1);
	}
	printf("%d",min(ans,(int)s.size()/2));
}