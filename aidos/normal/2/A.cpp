#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main () {
string s[1010];
int n, a[1010], m=0;
map <string, int> t, k;
cin >> n;     
for(int i=0; i<n; i++){
	cin >> s[i] >> a[i];
	t[s[i]]+=a[i];	
}
for(map <string, int>::iterator it=t.begin(); it!=t.end(); it++)
	if((*it).second > m) m = (*it).second;
for(int i=0; i<n; i++){
	k[s[i]]+=a[i];
	if(k[s[i]]>=m && t[s[i]]==m){
		cout << s[i];
		return 0;
	}
}
return 0;
}