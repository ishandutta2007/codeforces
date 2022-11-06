#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n, a[int(2e5+4)], mn = 2e9;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",a+i);
		mn = min(mn, a[i]);
	}
	int fst = -1, cur = 0, rek = -1;
	rep(i,0,n){
		if(a[i] > mn){
			++cur;
		} else {
			if(fst == -1)
				fst = cur;
			rek = max(rek, cur);
			cur = 0;
		}
	}
	rek = max(rek, cur+fst);
	rek = max(rek, cur);
	cout << (long long)n*mn + rek << endl;
}