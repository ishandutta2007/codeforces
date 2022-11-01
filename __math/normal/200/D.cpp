#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

istringstream GetISS(){
	string s;
	getline(cin,s);
	return istringstream(s);
}

enum{INT,DBL,STR,T_TP};

struct TPLT{
	string name;
	vector<int> args;
};

int getTP(string ty_name){
	if(ty_name == "int") return (INT);
	else if(ty_name == "string") return(STR);
	else if(ty_name == "double") return(DBL);
	else return(T_TP);
}
int n,m,k;

void solve(vector<TPLT>& tp,map<string,int>& mp)
{
	string s;
	getline(cin,s);
	replace(s.begin(),s.end(),'(',' ');
	replace(s.begin(),s.end(),')',' ');
	replace(s.begin(),s.end(),',',' ');
	istringstream iss(s);
	string name,buf;
	vector<int> args;
	iss>>name;
	int ans = 0;
	while(iss>>buf){
		args.push_back(mp[buf]);
	}
	for (int j = 0; j < n; j++){
		if(name != tp[j].name) continue;
		if(args.size() != tp[j].args.size()) continue;
		int l;
		for (l = 0; l < (int)args.size(); l++){
			if(tp[j].args[l] == INT && args[l] == INT) continue;
			if(tp[j].args[l] == DBL && args[l] == DBL) continue;
			if(tp[j].args[l] == STR && args[l] == STR) continue;
			if(tp[j].args[l] == T_TP) continue;

			break;
		}
		if(l == (int)args.size())
			ans++;
	}
	printf("%d\n",ans);
}

int main()
{
	GetISS() >> n;
	vector<TPLT> tp(n);
	for (int i = 0; i < n; i++){
		string s;
		getline(cin,s);
		replace(s.begin(),s.end(),'(',' ');
		replace(s.begin(),s.end(),')',' ');
		replace(s.begin(),s.end(),',',' ');
		istringstream iss(s);
		string buf;
		iss>>buf;
		iss>>tp[i].name;
		while(iss>>buf){
			tp[i].args.push_back(getTP(buf));
		}
	}
	GetISS() >> m;
	map<string,int> mp;
	for (int i = 0; i < m; i++){
		string s;
		getline(cin,s);
		replace(s.begin(),s.end(),'(',' ');
		replace(s.begin(),s.end(),')',' ');
		replace(s.begin(),s.end(),',',' ');
		istringstream iss(s);
		string name,type;
		iss>>type;
		iss>>name;
		mp[name] = getTP(type);
	}

	GetISS() >> k;
	for (int i = 0; i < k; i++){
		solve(tp,mp);
	}

	return 0;
}