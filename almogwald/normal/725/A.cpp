#include <iostream>
#include <string>

using namespace std;
int main()
{
	
	int n , sum =0 ,i=0;
	string line;
	cin >> n;
	cin >> line;
	while (i<n && line[i++] == '<') {
		sum++;
	}
	i = n - 1;
	while (i>=0 && line[i--] == '>') {
		sum++;
	}
	cout << sum << '\n';
	//delete[] pizza;
	return 0;
}