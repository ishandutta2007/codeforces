#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
string s[10];
int k=0, i, j;
for(i=0; i<8; i++){
	cin >> s[i];
	if(s[i]=="BBBBBBBB"){
		k++;
	}
}
for(i=0; i<8; i++){
	int t=0;
	for(j=0; j<8;j++){
		if(s[j][i]=='B') t++;
	}
	if(t==8) k++;
}
if(k!=16)cout << k;
else cout << 8;
return 0;
}