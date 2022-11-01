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

int n;
ll p[50];
ll a[5];

int main()
{
	cin>>n;
	for(int i =0 ;i < n; i++) cin>>p[i];
	for(int i =0 ;i < 5; i++) cin>>a[i];

	vector<ll> ans(5);
	ll pt = 0;
	for(int i =0 ;i < n; i++){
		pt += p[i];
		for(int j = 4; j >= 0; j--){
			if(pt >= a[j]){
				ll add = pt / a[j];
				ans[j] += add;
				pt %= a[j];
			}
		}
	}

	for(int i =0 ; i < 5; i++){
		cout << ans[i];
		if(i == 4) cout << endl; else cout << " ";
	}
	cout << pt << endl;

	return 0;
}