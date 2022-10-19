#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
int sm, sm1;
vector <int> pat;
int main()
{
	cin >> s;
	int i1;
	for (i1 = s.length() - 1; i1 >= 0 ; i1--)
	{
		if(s[i1] == '#') break;
		if(s[i1] == '(') sm1--;
		else sm1++;
		if(sm1 < 0) 
		{
			//cout << 1;
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < i1; i++)
	{
		if(s[i] == '(') sm++;
		else sm--;
		if(s[i] == '#') pat.push_back(1), s[i] = ')';
		if(sm < 0)
		{
			//cout << 3;
			cout << -1;
			return 0;
		}

	}
	if(sm <= sm1) {
		cout << -1;
		return 0;
	}

	pat.push_back(sm - sm1);

	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i] << endl;
	}
	return 0;
}