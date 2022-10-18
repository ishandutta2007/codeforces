#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string s;
	int i,flag=0;
	cin >> s;
	for(i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-i-1]) flag++;
	if(flag==1 || (flag==0 && s.size()%2)) cout << "YES\n";
	else cout << "NO\n"; 
}