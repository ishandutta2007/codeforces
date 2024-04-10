#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

struct passenger{
	string name;
	int level;
	int place;
	passenger(string NAME, int LEVEL,int pl){
		name=NAME;
		level=LEVEL;
		place=pl;
	}
	passenger(){};
};

bool comp(const passenger & x,const passenger & y){
	if (x.level!=y.level){
		if (x.level<y.level)
			return true;
		else return false;
	}
	if (x.place<y.place)
		return true;
	return false;
}

int n;
vector <passenger > ship;


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	scanf("%d ",&n);
	for (int i=0;i<n;++i){
		string name;
		cin>>name;
		scanf(" ");
		string level;
		cin>>level;
		int lev;
		scanf(" ");
		if (level=="rat")
			lev=0;
		if (level=="woman" || level=="child")
			lev=1;
		if (level=="man")
			lev=2;
		if (level=="captain")
			lev=3;
		ship.pb(passenger(name,lev,i));
	}
	sort(ship.begin(),ship.end(),comp);
	for (int i=0;i<n;++i)
		printf("%s\n",ship[i].name.c_str());
	return 0;
}