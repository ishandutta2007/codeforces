#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int n;
long long k=0;
cin  >> n;
for(int i=n-1; i>0; i--){
	k+= i*(n-i);	
}             
cout << k+n;
return 0;
}