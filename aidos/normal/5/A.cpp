#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main () {   
int n, t=0;
set <string> v;
string s; 
for(int i=0;	getline(cin, s) ; i++){
	if(s[0]=='+'){
		v.insert(s.substr(1));
	}
	else if(s[0]=='-'){
		v.erase(s.substr(1));
	}
	else {   
		int k=s.size();
		for(int i=0; i<k; i++){
			if(s[i]==':') {
				t+= (k-i-1)*v.size();	
			}
		}           
	}
}
cout << t;
return 0;
}