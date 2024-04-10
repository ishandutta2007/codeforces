#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

int main()
{
	int n,flag=1,i,j;
	string s;
	cin >> n >> s;
	while(flag)
	{
		flag=0;
		for(i=0;i<s.size()-1;i++)
			if((s[i]=='a' || s[i]=='e' || s[i]== 'i' || s[i]=='o' || s[i]=='u' || s[i]=='y') && (s[i+1]=='a' || s[i+1]=='e' || s[i+1]== 'i' || s[i+1]=='o' || s[i+1]=='u' || s[i+1]=='y'))
			{
				for(j=i+1;j<s.size()-1;j++)
					s[j]=s[j+1];
				s.pop_back();
				flag=1;
			}
	}
	cout << s << "\n";
}