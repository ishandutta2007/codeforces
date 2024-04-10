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
string s;
cin >> s;
int t=s.size();
int k=0, d = t-1, a[t+10];
set < pair <double, int> > q;
for(int i=0; i<t; i++){
if(s[i]=='l'){
	a[d--]=i+1;		
}            
else {                           
	a[k++]=i+1;
}
}                               
for(int i=0; i<t;i++)
	cout << a[i] << " ";
return 0;
}