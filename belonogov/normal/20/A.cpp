#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = -1;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);2
//     freopen("out", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	for (; n > 0 && s[n - 1] == '/'; n--);
	if (n == 0){
		cout << "/" << endl;
		return 0;		
	}
	for (int i = 0; i < n; i++){
		if (s[i] != '/' || (i + 1 < n && s[i + 1] != '/'))
			cout << s[i];
	}
	cout << endl;
 
 
    return 0;
}