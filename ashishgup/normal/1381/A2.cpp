#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int l, r;
bool rev = 0;
string a, b;
vector<int> v;

char flip(char ch)
{
	if(ch == '0')
		return '1';
	return '0';
}

char get()
{
	if(!rev)
		return a[r];
	else
		return flip(a[l]);
}

void perform(int idx)
{
	if(idx == 0)
	{
		v.push_back(idx);
		return;
	}
	if(!rev)
	{	
		if(flip(a[l]) != b[idx])
			v.push_back(0);
		v.push_back(idx);
		l++;
	}
	else
	{
		if(a[r] != b[idx])
			v.push_back(0);
		v.push_back(idx);
		r--;
	}
	rev ^= 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		rev = 0;
		v.clear();
		cin >> n;
		cin >> a >> b;
		l = 0, r = n - 1;
		for(int i = n - 1; i >= 0; i--)
		{
			if(get() != b[i])
				perform(i);
			else
			{
				if(!rev)
					r--;
				else
					l++;
			}
		}
		cout << v.size() << " ";
		for(auto &it:v)
			cout << it + 1 << " ";
		cout << endl;
	}
	return 0;
}