#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;
#define lli long long int
lli nums[200000];
vector <lli> times,p; 
int k,now=0;

bool bigger(lli a,lli b) {
	if (a>b) return true;
	return false;
}


lli push(int n) {
	for (int i=now;i<times[n]+now;++i) p.push_back(nums[i]);
	sort(p.begin(),p.end(),bigger);
	lli sum=0;
	for (int i=0;i<p.size();++i) {
		if (i>=k) break;
		sum+=p[i];
	}
	now+=times[n];
	p.clear();
	return sum;
}


int main () {
	int tmp=1,n;
	lli sum=0;
	cin >> n >> k;
	for (int i=0;i<n;++i) cin >> nums[i];
	string s;
	cin >> s;
	char a=s[0];
	for (int i=1;i<n;++i) {
		if (a==s[i]) tmp++;
		else {
			times.push_back(tmp);
			a=s[i];
			tmp=1;
		}
	}
	times.push_back(tmp);
	for (int i=0;i<times.size();++i) sum+=push(i);
	cout << sum << endl;
}