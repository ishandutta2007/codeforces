#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> arr;
string str;

int main()
{
	cin >> str;

	for(int i=0;i<str.size();i++) {
		string s;
		for(int j=i;j<i+str.size();j++) {
			s.push_back(str[j%str.size()]);
		}
		if(arr.count(s)==0) {
			arr.insert(s);
		}
	}

	printf("%lu\n",arr.size());

	return 0;
}