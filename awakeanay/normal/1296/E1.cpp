/*
Author: AwakeAnay
Date: 04/02/2020
Time: 20:34:46
*/

#include <iostream>

#define MAXN 400005
 
int bit[MAXN];
int ans[MAXN];

void add(int x, int val) {
	x += 1;
	while(x < MAXN) {
		bit[x] = std::max(bit[x], val);
		x += x&(-x);
	}
}
 
int max(int x) {
	x += 1;
	int ret = 0;
	while(x > 0) {
		ret = std::max(ret, bit[x]);
		x -= x&(-x);
	}
	return ret;
}
 
int lis(int seq[], int n) {
	for(int i = 0; i < n; i++) {
		ans[i] = max(seq[i]-1)+1;
		add(seq[i], ans[i]);
	}
	return max(MAXN);
}

#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	int seq[n];
	
	for(int i = 0; i < n; i++) {
		seq[i] = 'z' - s[i];
	}
	
	int max = lis(seq, n);
	
	if(max <= 2)
		std::cout << "YES" << std::endl;
	else {
		std::cout << "NO" << std::endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++) {
		std::cout << max-ans[i];
	}
	
	std::cout << std::endl;
	
    return 0;
}