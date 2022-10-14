#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;

#define lli long long int

lli nums[100000];
lli n,m,k,now=0,o=0,a=0,f;

lli find(lli to) {
	lli j=0;
	while (nums[now]<=to and now<m) {
		now++;
		j++;
	}
	return j;
}


int main () {
	cin >> n >> m >> k;
	f=k;
	lli q;
	for (int i=0;i<m;++i) cin >> nums[i];
	while (a<=n) {
		if (now>=m) break;
		q=(nums[now]-a-1)/k;
		if (q>0 and f==k) a+=k*q;
		a+=f;
		f=find(a);
		if (f!=0) {
			o++;
		} else {
			f=k;
		}
	}
	cout << o << endl;
	return 0;
}