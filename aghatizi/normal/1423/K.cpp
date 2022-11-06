#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)

int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }
const int maxn = 1e6 + 10;
bool mark[maxn];
int ps[maxn];
int32_t main(){
	IOS;
	int n;
	cin >> n;
	mark[1] = true;
	for(int i=2; i<maxn; i++){
		if(!mark[i]){
			for(int j=2*i; j<maxn; j+=i)
				mark[j] = 1;
		}
	}

	for(int i=1; i<maxn; i++)
		if(mark[i])
			ps[i] = ps[i - 1];
		else
			ps[i] = ps[i - 1] + 1;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		int lim = sqrt(x);
		while(lim * lim <= x)
			lim++;
		lim--;
		//cout << "WTF" << lim << endl;
		cout << ps[x] - ps[lim] + 1 << endl;
	}
}