#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {  
string n, m, l="";
int z=0;
vector <int> v;
cin >> n >> m;
for(int i=0; i<n.size(); i++)
	if(n[i]=='0') z++;
	else v.push_back(n[i]-'0');
sort(v.begin(), v.end());
if(v.begin()!=v.end()){
l = ('0' + v[0]);  
while(z){
	l = l + '0';
	z--;
}
for(vector<int>::iterator it = v.begin()+1; it!=v.end(); it++){
        int d = (int)(*it);
		l = l + (char)( d + '0');
}
if(l==m){
	cout <<"OK";
}
else cout << "WRONG_ANSWER";
}
else
if(n==m){
	cout <<"OK";
}
else cout << "WRONG_ANSWER";
return 0;
}