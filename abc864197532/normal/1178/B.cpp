#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
vector<lli> v,o;
int all=0;

int main () {
	string s;
	cin >> s;
	char aa=s[0];
	int num=1;
	fop(i,1,s.length()) {
		if (aa==s[i]) {
			num++;
		} else {
			if (aa=='o') {
				if (v.size()!=0) {
					o.push_back(num);
				}
			} else {
				all+=num;
				all--;
				v.push_back(all);	
			}
			num=1;
			aa=s[i];
		}
	}
	if (aa=='v') {
		all+=num;
		all--;
		v.push_back(all);
	}
	lli sum=0;
	fop(i,0,o.size()) {
		sum+=o[i]*v[i]*(v[v.size()-1]-v[i]);
	}
	cout << sum << endl;
}