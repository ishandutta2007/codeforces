#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

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

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

const int C = 100000 * 2;
int sum[C];
int le[C];

int main(){
	string s;
	cin >> s;
	int n = sz(s);
	stack<int> st;
	memset(le,-1,sizeof(le));
	FOR(i,n){
		if(s[i] == '[' || s[i] == '(') st.push(i);
		else if(s[i] == ')'){
			if(!st.empty() && s[st.top()] == '('){ le[i] = st.top(); st.pop(); }
			else { stack<int> b; swap(b,st); }
		}
		else if(s[i] == ']'){
			if(!st.empty() && s[st.top()] == '['){ le[i] = st.top(); st.pop(); }
			else { stack<int> b; swap(b,st); }
		}
	}
	for(int i = 0; i < n; i++) sum[i+1] = sum[i] + (s[i] == '[');
	for(int i = 0; i < n; i++) if(le[i] > 0 && le[le[i] - 1] != -1) le[i] = le[le[i] - 1];

	int ans = 0;
	int l,r = 0;
	for(int i = 0; i < n; i++){
		if(le[i] != -1){
			int cl = le[i];
			int cr = i;
			int c_ans = sum[cr] - sum[cl];
			if(c_ans > ans){
				ans = c_ans;
				l = cl,r = cr;
			}
		}
	}
	if(ans){
		cout << ans << endl;
		for(int i = l; i <= r; i++) putchar(s[i]);
		puts("");
	} else {
		puts("0\n");
	}


	return 0;
}