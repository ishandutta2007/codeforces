#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli nums[200000];
int n;

int find(lli a) {
	int begin=0,end=n,p=(begin+end)/2;
	while (true) {
		p=(begin+end)/2;
		if (end-begin==1) return begin;
		if (nums[p]>a) end=p;
		else if (nums[p]<=a) begin=p;
	}
}


int main () {
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> nums[i];
		if (nums[i]<0) nums[i]=-nums[i];
	}
	sort(nums,nums+n);
	lli sum=0;
	for (int i=0;i<n-1;++i) {
		int f=find(nums[i]*2);
		sum+=(f-i);
	}
	cout << sum << endl;
}