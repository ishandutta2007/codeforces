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

const int maxn = 1e5 + 2;
const int inf = 1e9;


int a[maxn];
int b[maxn];
int next[maxn];
bool use[maxn];
vector < pair < int, int > > answer;

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, step;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	memset(b, -1, sizeof(b));
	for (int i = n - 1; i >= 0; i--){
		next[i] = b[a[i]];
		b[a[i]] = i;		
	}
	for (int i = 0; i < n; i++){
		if (use[a[i]]) 
			continue;
		use[a[i]] = 1;
		if (next[i] == -1){
			answer.pb(mp(a[i], 0));
			continue;				
		}
		step = next[i] - i;
		bool flag = 1;
		int j = i;
		for (; next[j] != -1; j = next[j]){
			if (next[j] - j != step)
				flag = 0;			
		}
		if (flag)
			answer.pb(mp(a[i], step));
		
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i].fr << " " << answer[i].sc << endl;
	
 
    return 0;
}