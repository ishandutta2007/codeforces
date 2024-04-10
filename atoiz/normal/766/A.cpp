#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	if (a.compare(b) == 0) cout << -1 << endl;
	else if (a.size() < b.size()) cout << b.size() << endl;
	else cout << a.size() << endl;
}