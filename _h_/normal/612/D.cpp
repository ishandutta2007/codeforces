#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int k,n,l,r,cnt=0;
	vector<pair<int,bool> > lr;
	vector<int> ans;
	scanf("%d%d",&n,&k);
	rep(_,0,n){
		scanf("%d%d",&l,&r);
		lr.push_back(make_pair(l,false));
		lr.push_back(make_pair(r,true));
	}
	sort(lr.begin(),lr.end());
	for(auto &p : lr){
		if(p.second){
			if(cnt-- == k){
				ans.push_back(p.first);
			}
		} else {
			if(++cnt == k)
				ans.push_back(p.first);
		}
	}
	printf("%d\n",ans.size()/2);
	for(int i = 0; i < ans.size(); i+=2){
		printf("%d %d\n",ans[i],ans[i+1]);
	}
}