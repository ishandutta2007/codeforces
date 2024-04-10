#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
int n;
	
int main() 
{
	cin >> n;
	int mk = sqrt(n);
	cout << mk + (n - 1) / mk + 1;
	return 0;
}