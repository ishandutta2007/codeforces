#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define y1 qwqwqwqw

using namespace std;

const int maxn = 1e6 + 11;
const ll mod = 998244353;
int n;
string s[500];

string get(string x) {
	string ret = "";
     for (int i = 0; i < x.size(); i++)
     	if (x[i] == 'u')
     		ret += "oo";
     	else
     		ret += x[i];
     x = ret;
     int bad = 1;
     while (bad) {
      	bad = 0;
      	string nw = "";
      	for (int i = 0; i < x.size(); i++)
      		if (i + 1 < x.size() && x[i] == 'k' && x[i + 1] == 'h') {
      		 	nw += 'h';
      		 	i++;
      	     	bad=1;
      		}else {
      		 	nw += x[i];
      		}
          x = nw;
     }
     return x;
}	
bool ok(int i, int j) {
	if (s[i] != s[j])
 	return 0;
 return 1;
}
int main() {
     scanf("%d\n", &n);
     for (int i = 1; i <= n; i++) {
      	getline(cin, s[i]);
      	s[i] = get(s[i]);
     }
     int res = 0;
     for (int i = 1; i <= n; i++) {
      	int bad = 0;
      	for (int j = 1; j < i; j++)
      		if  (ok(i, j)){
      		 	bad = 1;
      		 	break;
      		}
      	if (!bad) {
      		res++;
      	}
     }
     cout << res;
	return 0;
}