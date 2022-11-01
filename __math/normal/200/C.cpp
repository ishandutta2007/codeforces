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


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

//BEGIN!!!

struct RESULTS{
	int pts,diff,goal,cnt,id;
	string name;
};

RESULTS t[4];
vector<string> teams;
int getTeamNum(string name)
{
	vector<string>::iterator it;
	it = find(teams.begin(),teams.end(),name);
	if(it == teams.end()){
		teams.push_back(name);
		int id =(int)teams.size() - 1;
		t[id].name = name;
		return id;
	}else {
		return it - teams.begin();
	}
}

bool cmp(const RESULTS& x,const RESULTS &y){
	if(x.pts != y.pts) return greater<int>()(x.pts,y.pts);
	if(x.diff != y.diff) return greater<int>()(x.diff,y.diff);
	if(x.goal != y.goal) return greater<int>()(x.goal,y.goal);
	return less<string>()(x.name,y.name);
}

int get_opp()
{
	for (int i = 1; i < 4; i++){
		if(t[i].cnt == 2) return i;
	}
	return -1;
}

template<class T>
void f(int a,int b,int t1,int t2,T& team){
	team[t1].goal += a;
	team[t2].goal += b;
	team[t1].diff += a-b;
	team[t2].diff += b-a;
	team[t1].cnt++;
	team[t2].cnt++;
	if(a > b){
		team[t1].pts += 3;
	} else if(a < b){
		team[t2].pts += 3;
	} else {
		team[t1].pts++; team[t2].pts++;
	}
}

bool ok(int goal,int miss,int op){
	vector<RESULTS> r(t,t+4);
	f(goal,miss,0,op,r);
	sort(r.begin(),r.end(),cmp);
	if(r[0].id == 0 || r[1].id == 0) return true;
	else return false;
}

int main()
{
	getTeamNum("BERLAND");

	for (int i = 0; i < 4; i++){
		t[i].id = i;
	}
	for (int i = 0; i < 5; i++){
		char buf1[100],buf2[100];
		int a,b;
		scanf("%s %s %d:%d",buf1,buf2,&a,&b);
		int t1 = getTeamNum(buf1);
		int t2 = getTeamNum(buf2);
		f(a,b,t1,t2,t);
	}

	int op = get_opp();
	for (int i = 1; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if(ok(i + j,j,op)){
				printf("%d:%d\n",i+j,j);
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}