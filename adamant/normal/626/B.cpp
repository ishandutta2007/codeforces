#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int R = count(begin(s), end(s), 'R');
	int B = count(begin(s), end(s), 'B');
	int G = count(begin(s), end(s), 'G');
	
	if(R > 0 && B > 0 && G > 0)
		cout << "BGR\n";
	
	else if(B == 0 && G == 0)
		cout << "R\n";
	else if(R == 0 && G == 0)
		cout << "B\n";
	else if(R == 0 && B == 0)
		cout << "G\n";
	
	else if(B == 0)
		if(R == 1 && G == 1)
			cout << "B\n";
		else if(R == 1 && G > 1)
			cout << "BR\n";
		else if(R > 1 && G == 1)
			cout << "BG\n";
		else
			cout << "BGR\n";
			
	else if(G == 0)
		if(R == 1 && B == 1)
			cout << "G\n";
		else if(R == 1 && B > 1)
			cout << "GR\n";
		else if(R > 1 && B == 1)
			cout << "BG\n";
		else
			cout << "BGR\n";
			
	else if(R == 0)
		if(B == 1 && G == 1)
			cout << "R\n";
		else if(B == 1 && G > 1)
			cout << "BR\n";
		else if(B > 1 && G == 1)
			cout << "GR\n";
		else
			cout << "BGR\n";
	
	return 0;
}