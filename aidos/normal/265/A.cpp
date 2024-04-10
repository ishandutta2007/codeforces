#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
string s, t;
cin >> s >> t;
int q=s.size(), w=t.size(), i=0, j=0;
while(i<w){
	if(t[i]==s[j]) j++;
	i++;	
}
cout << j+1;
return 0;
}