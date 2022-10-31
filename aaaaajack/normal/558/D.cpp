#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define inf (1LL<<62)
using namespace std;
int main(){
	int h,q;
	long long yl,yr;
	vector<pair<long long,long long> > gg;
	scanf("%d%d",&h,&q);
	yl=1LL<<h-1;
	yr=1LL<<h;
	while(q--){
		int i,s;
		long long l,r;
		long long tl,tr;
		scanf("%d%I64d%I64d%d",&i,&l,&r,&s);
		tl=l<<(h-i);
		tr=(r+1)<<(h-i);
		if(s){
			yl=max(yl,tl);
			yr=min(yr,tr);
		}
		else{
			gg.push_back(make_pair(tl,tr));
		}
	}
	sort(gg.begin(),gg.end());
	if(yl<yr){
		for(int i=0;i<gg.size();i++){
			if(gg[i].first<=yl&&gg[i].second>yl) yl=gg[i].second;
		}
		if(yl<yr){
			long long tl=yl+1;
			for(int i=0;i<gg.size();i++){
				if(gg[i].first<=tl&&gg[i].second>tl) tl=gg[i].second;
			}
			if(tl<yr) puts("Data not sufficient!");
			else printf("%I64d\n",yl);
		}
		else{
			puts("Game cheated!");
		}
	}
	else{
		puts("Game cheated!");
	}
	return 0;
}