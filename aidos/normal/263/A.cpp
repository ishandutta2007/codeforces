#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int x, y, z;
for(int i=0; i<5; i++)
	for(int j=0; j<5; j++){
		cin >> z;
		if(z) x = abs(2-i)+abs(2-j);
	}
cout << x;
return 0;
}