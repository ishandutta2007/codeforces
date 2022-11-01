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
#define FOR(i,count) for (int i = 0; i < count; i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> v[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
const int MODULO = 1000000007;

//BEGIN!!!

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int comp(char ca,char cb)
{
	if(ca == 'R'){
		if(cb == 'R') return 0; 
		else if(cb == 'S') return -1;
		else return 1;
	} else if(ca == 'S') {
		if(cb == 'R') return 1; 
		else if(cb == 'S') return 0;
		else return -1;
	} else{
		if(cb == 'R') return -1; 
		else if(cb == 'S') return 1;
		else return 0;
	}
}

int n;
string a,b;
int a_win= 0, b_win = 0;
int la,lb;

void add(int loop)
{
	for(int i = 0; i < loop; i++){
		char ca = a[i%la],cb = b[i%lb];
		int ret = comp(ca,cb);
		if(ret == 1) a_win++;
		else if(ret == -1) b_win++;
	}
}

int main(){

	cin>>n>>a>>b;
	la = sz(a);lb = sz(b);
	int loop = la * lb / gcd(la,lb);
	add(loop);
	a_win *= n / loop;
	b_win *= n / loop;
	add(n%loop);

	printf("%d %d\n",a_win,b_win);
	
	return 0;
}