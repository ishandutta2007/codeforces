#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	int n,m;
	cin >> n >> m;
	if(n == 1)
		cout << 1;
	else if(n - m > m - 1)
		cout << m+1;
	else 
		cout << m-1;
	cout << endl;
}