#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		int c,d;
		cin >> a >> c >> b >> d;
		if(a.size()+c>b.size()+d)
			cout << ">\n";
		else if(a.size()+c<b.size()+d)
			cout << "<\n";
		else
		{
			while(a.size()<b.size()) a+='0';
			while(a.size()>b.size()) b+='0';
			if(a==b)
			{
				cout << "=\n";
			}
			else if(a<b) cout << "<\n";
			else cout << ">\n";
		}
	}
	return 0;
}