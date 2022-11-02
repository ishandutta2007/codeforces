#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
int a[100100], n, k;
cin >> n >> k;
for(int i=0; i<n; i++)
	scanf("%d", &a[i]);
set <int> s;
sort(a, a+n);
for(int i=0; i<n; i++){
	if(a[i]%k!=0 || s.find(a[i]/k)==s.end()){
		s.insert(a[i]);
	}
}
cout << s.size();
return 0;
}