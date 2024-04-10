#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 100;
string name[maxn];
set <string> mystr;
map <string, bool> mark;
map <string, pair <int, int> > dp;
map <string, vector <string> > v;
map <string, bool> iscome;

pair<string, pair <int, int> > arr[2 * maxn];

void dfs (string x, int minr, int minlen){
	mark[x] = true;
//	cout << x << " " << minr << " " << minlen << endl;
	dp[x] = min(dp[x], make_pair(minr, minlen));
	for (int i = 0; i < v[x].size(); i++)
		if (!mark[v[x][i]])
			dfs(v[x][i], minr, minlen);
	return;
}

int count_r(string s){
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'r')
            k ++;
    return k;
}

string make_lowercase(string a){
    for (int i = 0; i < a.size(); i++)
        if (a[i] - 'a' < 0)
            a[i] = a[i] - 'A' + 'a';
    return a;
}

bool cmp(pair<string, pair<int, int> > fi, pair<string, pair<int, int> > se) {
	if (fi.S.F < se.S.F)
		return true;
	if (fi.S.F > se.S.F)
		return false;
	return fi.S.S < se.S.S;
}

int main (){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> name[i];
		name[i] = make_lowercase(name[i]);
		mystr.insert(name[i]);
		iscome[name[i]] = true;
	}
    cin >> m;
    for (int i = 1; i <= m; i++){
        string a, b;
        cin >> a >> b;
        a = make_lowercase(a);
        b = make_lowercase(b);
		mystr.insert(a);
		mystr.insert(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	for (set<string>::iterator it = mystr.begin(); it != mystr.end(); it ++){
		dp[*it].F = count_r(*it);
		dp[*it].S = (*it).size();
		arr[cnt] = make_pair(*it, make_pair(count_r(*it), (*it).size()));
		cnt++;
	}
	sort(arr, arr + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		if (!mark[arr[i].F])
			dfs(arr[i].F, arr[i].S.F, arr[i].S.S);
	}
	long long totr = 0, totlen = 0;
	for (int i = 1; i <= n; i++){
		totr += dp[name[i]].F;
		totlen += dp[name[i]].S;
	}
	cout << totr << " " << totlen << endl;
}