#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

char s[500001];

int main()
{
	scanf("%s", s);
	
	vector<int> v;
	
	long double ans = 0;
	
	int len;
	v.push_back(-100);
	for(int i = 0; s[i] != '\0'; ++i)
	{
		char j = s[i];
		if(j == 'I' or j == 'E' or j == 'A' or j == 'O' or j == 'U' or j == 'Y')
			v.push_back(i);
		len = i;
	}
	v.push_back(1e+6);
	++len;
	/*for(int i : v)
		cout << i << " ";
	
	cout << endl;*/
	long long plu = 0;
	for(int i = 1; i <= len; ++i)
	{
		ans += (v.size() - 2 + plu) /  (long double) i;
		//cout << i << " " << ans << " " << plu << endl;
		int l = 0, r = v.size() - 1;
		while(l != r)
		{
			int m = (l + r) / 2;
			if(v[m] >= i)
				r = m;
			else
				l = m + 1;
		}
		//cout << "left " << l << " " << v[l] << endl;
		int lb = l;
		l = 0; r = v.size() - 1;
		while(l != r)
		{
			int m = (l + r) / 2;
			if(v[m] >= (len - i))
				r = m;
			else
				l = m + 1;
		}
		int rb = l;
		if(lb < rb)
			plu += rb - lb;
		else
			plu += rb - lb;
		//cout << "right " << l << " " << v[l] << endl;
	}
	cout.precision(10);
	cout << ans << endl;
    
    return 0;
}