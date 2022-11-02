#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>    
using namespace std;
int main () {   
int n, k, i, j, m, l, t;
string s;
cin >>k;
for(i=0; i<k; i++){
cin >> n;
if(360%(180-n)==0){
	cout << "YES\n";
}
else cout << "NO\n";
}
return 0;
}