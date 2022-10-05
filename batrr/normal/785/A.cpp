#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
using namespace std;
#define f first
#define s second

int main() {
	//freopen("disease.in","r", stdin);
	//freopen("disease.out","w", stdout);
	int  n;
	cin >> n;
	string s;
	int k = 0;
	for(int i = 0; i < n; i++){
	    cin >> s;
	    if(s[0] == 'T')k+=4;
	    else if(s[0] == 'C')k+=6;
	    else if(s[0] == 'O')k+=8;
	    else if(s[0] == 'D')k+=12;
	    else k+=20;
	}
	cout<<k;
}