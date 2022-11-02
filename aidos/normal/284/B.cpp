#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#define pb push_back
#define mp make_pair
using namespace std;
int main () {                   
map <char, int> m;
m['I'] = 0, m['A']=0, m['F']=0;
string s;
int n;
cin >> n >> s; 
for(int i=0; i<n; i++)
	m[s[i]]++;
if(m['I']==0) cout << m['A'];
else if(m['I']==1) cout << 1;
else cout << 0;
return 0;
}