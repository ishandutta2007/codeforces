#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
typedef pair<int, int> pii;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);
string s;
vector<int> vc;
int main()
{
//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	int i; 
	getline(cin,s);
	int ls=s.length();
	bool log=1;
	for(i=0;i<ls;i++)
	{
		if(s[i]=='-'){vc.pb(1);}else{vc.pb(0);}
		if(vc.size()>=2&&vc[vc.size()-1]==vc[vc.size()-2]){vc.ppb();vc.ppb();}
	}
	if(vc.size()==0){printf("Yes");}else{printf("No");}
	return 0;
}