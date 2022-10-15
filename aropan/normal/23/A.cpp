#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

string s;


int main()
{
    cin >> s;
    int n = s.size();
    
    for (int l = n - 1; l > 0; l--)
    {
		for (int i = 0; i < n - l; i++)
		{
			string a = s.substr(i, l);
			string b = s.substr(i + 1);
			if (b.find(a) != string::npos)
			{
				printf("%d\n", l);
				return 0;
			}
		}
	}
	puts("0");
    return 0;
}