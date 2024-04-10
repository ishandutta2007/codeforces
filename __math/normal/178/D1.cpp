#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define all(c) (c).begin(),(c).end()
#define FILL(c,val) memset((c),val,sizeof(c))

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

void solve1()
{
	int x;
	cin >> x;
	cout << x << endl << x << endl;
}

void solve2()
{
	int a[4];
	FOR(i,4) cin >> a[i];
	int sum =accumulate(a,a+4,0) / 2;
	cout << sum << endl;
	int id = find(a+1,a+4,sum - a[0]) - a;
	cout << a[0] << " " << a[id] << endl;
	int b[2];
	int cnt = 0;
	for(int i = 1; i < 4; i++){
		if(i == id) continue;
		b[cnt++] = i;
	}
	cout << a[b[0]] << " " << a[b[1]] << endl;
}

static int sa[][3] = {
	{0,1,2},
	{3,4,5},
	{6,7,8},
	{0,3,6},
	{1,4,7},
	{2,5,8},
	{0,4,8},
	{2,4,6}
};

int getSum(int *a,int i)
{
	int sum = 0;
	for(int j =0 ; j < 3; j++){
		sum += a[sa[i][j]];
	}
	return sum;
}

void solve3()
{
	int a[9];
	FOR(j,9) cin >> a[j];
	sort(a,a+9);
	do{
		int sum = getSum(a,0);
		int i;
		for(i = 1; i < 8; i++){
			if(sum != getSum(a,i)) break;
		}
		if(i == 8){
			cout << sum << endl;
			FOR(j,3) {
				printf("%d %d %d\n",a[j*3],a[j*3+1],a[j*3+2]);
			}
			return;
		}
	}while(next_permutation(a,a+9));

}

void solve4()
{
}

int main(){

	int n;
	cin >> n;

	if(n == 1) solve1();
	else if(n == 2) solve2();
	else if(n == 3) solve3();
	else solve4();

	return 0;
}