#include <iostream>
using namespace std;
#define f(n) for(i = 0; i < (n); i++)

int main()
{
	int n, i;
	cin >> n;
	if(!(n%2)){
		cout << "-1\n"; return 0; }
	 f(n) cout << i << " ";
	 cout<< "\n";
	 f(n) cout << i << " ";
	 cout<< "\n";
	  f(n) cout << (2*i)%n << " ";
	 return(0);
}