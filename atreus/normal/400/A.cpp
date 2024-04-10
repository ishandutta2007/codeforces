#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		vector <int> v;
		if (s[0] == 'X')
			a[0] = 1;
		for (int i = 1; i < s.size(); i++){
			a[i] = a[i - 1];
			if (s[i] == 'X')
				a[i] ++;
		}
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'X'){
				v.push_back(1);
				break;
			}
		for (int i = 0; i < s.size() / 2; i ++)
			if (s[i] == 'X' and s[i + 6] == 'X'){
				v.push_back(2);
				break;
			}
		for (int i = 0; i < s.size() / 3; i ++)
			if (s[i] == 'X' and s[i + 4] == 'X' and s[i + 8] == 'X'){
				v.push_back(3);
				break;
			}
		for (int i = 0; i < s.size() / 4; i ++)
			if (s[i] == s[i + 3] and s[i] == s[i + 6] and s[i] == s[i + 9] and s[i] == 'X'){
				v.push_back(4);
				break;
			}
		bool cur = true, cur1 = true;
		for (int i = 0; i < s.size(); i ++){
			if (s[i] != 'X'){
				if (i % 2 == 0)
					cur = false;
				else
					cur1 = false;
			}
		}
		if (cur || cur1)
			v.push_back(6);
		if (a[11] == 12)
			v.push_back(12);
		cout << v.size() << " ";
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << "x" << 12 / v[i] << " ";
		}
		cout << endl;
	}
}