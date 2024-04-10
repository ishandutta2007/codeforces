#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

string s[500000];

int main()
{
	int n,i,j;
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(i=0;i<n;i++) cin >> s[i];
	for(i=n-2;i>=0;i--)
	{
		j=s[i].size();
		if(s[i]>s[i+1])
			for(j=0;j<s[i].size();j++)
				if(s[i][j]>s[i+1][j]) break;
		s[i].resize(j); 
	}
	for(i=0;i<n;i++) cout<< s[i]<< "\n"; 
}