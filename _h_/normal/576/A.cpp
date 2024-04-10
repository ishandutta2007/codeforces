#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n;
	scanf("%d",&n);
	vector<int> ans;
	bool eras[1100] = {};
	rep(i,2,1100){
		if(!eras[i]){
			int p = i;
			while(p <= n){
				ans.push_back(p);
				p *= i;
			}
			for(int j = i+i; j < 1100; j += i)
				eras[j] = 1;
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto y : ans)
		printf("%d ",y);
	puts("");
}