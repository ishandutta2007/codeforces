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
int a[100000];

int main(){
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	int id = min_element(a,a+n) - a;
	for (int i = 0; i < n; i++){
		if(i == id) continue;
		if(a[i] == a[id]){
			puts("Still Rozdil");
			return 0;
		}
	}

	printf("%d\n",id + 1);

	return 0;
}