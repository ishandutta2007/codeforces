#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
string names[100100];
int type[100100];
char tmp[100];

int toInt(string &x){
	int n = 0;
	for(int i = 0; i < x.size(); i++){
		n = n * 10 + x[i] - '0';
	}
	return n;
}

bool ok(string &x){
	if(x[0] == '0') return false;
	int m = 0;
	for(int i = 0; i < x.size(); i++){
		if(x[i] >= '0' && x[i] <= '9'){
			m = m * 10 + x[i] - '0';
		}else return false;
	}
	return m <= n;
}


int used[100100];

set<string> S;

string toString(int g){
	string R;
		while(g){
			R += g % 10 + '0';
			g/=10;
		}
	reverse(all(R));
	return R;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s%d", tmp, &type[i]);
		names[i] = tmp;
		S.insert(names[i]);
	}
	string R;
	for(int j = 3 * n; ; j++){
		R="";
		int g = j;
		while(g){
			R += g % 10 + '0';
			g/=10;
		}
		if(!S.count(R)){
			break;
		}
	}
	std::vector<int> good, ng;

	int cnt=0;
	for(int i = 0; i < n; i++){
		if(ok(names[i])){
			good.pb(i);
		}
		else ng.pb(i);
		cnt += type[i];
	}
	set<int> A, B, NA, NB;
	for(int i =1; i <= cnt; i++)
		A.insert(i);
	for(int i = cnt + 1; i <= n; i++){
		B.insert(i);
	}
	for(int i = 0; i < good.size(); i++){
		int ind = good[i];
		int num = toInt(names[ind]);
		A.erase(num);
		B.erase(num);
		if(type[ind]){
			if(num > cnt) NA.insert(ind);
		}
		else if(num <= cnt){
			NB.insert(ind);
		}
	}
	std::vector<pair<string, string> > ans;
	while(NA.size() + NB.size() > 0){
		if(NA.size() > 0 && A.size() > 0){
			int ind=*NA.begin();
			NA.erase(NA.begin());
			int y = *A.begin();
			A.erase(A.begin());
			ans.pb(mp(names[ind], toString(y)));
			B.insert(toInt(names[ind]));
		}
		else if(NB.size() > 0 && B.size() > 0){
			int ind=*NB.begin();
			NB.erase(NB.begin());
			int y = *B.begin();
			B.erase(B.begin());
			ans.pb(mp(names[ind], toString(y)));
			A.insert(toInt(names[ind]));
		}else {
			int ind = *NB.begin();
			NB.erase(NB.begin());
			A.insert(toInt(names[ind]));
			ans.pb(mp(names[ind], R));
			names[ind] = R;
			ng.pb(ind);
		}
	}
	for(int i = 0; i < ng.size(); i++){
		if(type[ng[i]]){
			int y = *A.begin();
			A.erase(A.begin());
			ans.pb(mp(names[ng[i]], toString(y)));
		}
		else {
			int y = *B.begin();
			B.erase(B.begin());
			ans.pb(mp(names[ng[i]], toString(y)));
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("move %s %s\n", ans[i].f.c_str(), ans[i].s.c_str());
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}