#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int w;
cin >> w;
if(w<4 || w%2){
	cout << "NO";
}
else cout << "YES";
return 0;
}