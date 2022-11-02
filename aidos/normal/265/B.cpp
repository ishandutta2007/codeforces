#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n, hx, t=0, b;
cin >> n >> hx;
t+=hx+1;
for(int i=n-1; i>0; i--){
	cin >> b;
	t+=abs(b-hx)+2;
	hx=b;
}
cout << t;
		
return 0;
}