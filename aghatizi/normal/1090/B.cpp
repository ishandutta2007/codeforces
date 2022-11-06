#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

map<string , string> desc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	vector<string> a;
	while(1)
	{
		getline(cin , s);
		if((int)s.size() > 1 && s[0] == 92 && s[1] == 'b')
			break;

		for(int i = 0; i < (int)s.size(); i++)
			if(s[i] == 92)
			{
				int j = i + 6;
				while(s[j] != '}')
					j++;

				a.pb(s.substr(i + 6 , j - i - 6));
			}
	}

	int pt = 0;

	bool f = 1;
	while(1)
	{
		getline(cin , s);

		if(s[0] == 92 && s[1] == 'e')
			break;

		string tmp = s.substr(9);
		while(tmp.back() != '}')
			tmp.pop_back();
		tmp.pop_back();

		desc[tmp] = s.substr(tmp.size() + 10);

		if(tmp != a[pt])
			f = 0;
		pt++;
	}

	if(f)
		return cout << "Correct" << endl , 0;

	cout << "Incorrect" << endl;

	cout << (char)(92) << "begin{thebibliography}{99}" << endl;
	for(auto x : a)
		cout << (char)(92) << "bibitem{" << x << "}" << desc[x] << endl;
	cout << (char)(92) << "end{thebibliography}";
}