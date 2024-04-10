#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int p[110], n;
cin >> n;
if(n%2==0){
	for(int i=0; i<n; i++)
		if(i%2==0){
			p[i] = i+2;
		}	
		else p[i] = i;
	for(int i=0;i<n; i++)
		cout << p[i] << " ";
}
else cout << -1;
return 0;
}