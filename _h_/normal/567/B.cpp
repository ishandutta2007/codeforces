#include <cstdio>
#include <vector>
#include <random>
#include <set>
#include <map> 
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	int n,cnt = 0;
	set<int> finns;
	scanf("%d",&n);
	vector<pair<bool,int> > logg(n);
	rep(i,0,n){
		char c;
		int r;
		scanf(" %c %d ",&c,&r);
		if(c == '+'){
			logg[i].first = 1;
		} else{
			logg[i].first = 0;
			if(!finns.count(r))
				++cnt;
		}
		logg[i].second = r;
		finns.insert(r);
	}
	int rek = cnt;
	rep(i,0,n){
		cnt += 2*logg[i].first - 1;
		rek = max(rek,cnt);
	}
	printf("%d\n",rek);
}