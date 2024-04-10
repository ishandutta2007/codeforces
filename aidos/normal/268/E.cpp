#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool f(pair <int, int> p, pair <int, int> l){
if(p.second==100){
	if(l.second==100)
			return p.first<l.first;
	return 1;
}
if(l.second == 100) return 0;
return p.first*p.second*(100-l.second) > l.first*l.second*(100-p.second);
}
int main () {   
double d;
int i, j, k, l, n;
pair <int, int> p[50000];
cin >> n;
for(i=0; i<n; i++){
	scanf("%d%d", &k, &l);
	p[i] = make_pair(k, l);          
}
sort(p, p+n, f);
double ans = 0, qq=0;
for(i=0; i<n; i++){
	ans += 1.0*(p[i].first*p[i].second+(100-p[i].second)*(qq+p[i].first))/100;
	qq += p[i].first*1.0*p[i].second/100;
}
printf("%.10f", ans);
return 0;                   
}