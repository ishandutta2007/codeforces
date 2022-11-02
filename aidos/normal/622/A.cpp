#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	int c=1;
	while( n > c){
	    n-=c;
	    c++;
	}
	cout << n << endl;
}