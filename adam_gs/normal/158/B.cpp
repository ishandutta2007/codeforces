#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, p, p1=0, p2=0, p3=0, p4=0;
	cin >> n;
	rep(i, n) {
		cin >> p;
		if(p==1)++p1;
		if(p==2)++p2;
		if(p==3)++p3;
		if(p==4)++p4;
	}
	p=p4;
	p4=min(p1, p3);
	p+=p4;
	p3-=p4;
	p1-=p4;
	p+=p3;
	p+=p2/2;
	if(p2%2==1)p1+=2;
	p+=(p1+3)/4;
	cout << p;
}