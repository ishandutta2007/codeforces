#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll inf = 1LL<<60;
const ld eps = 1e-14;
const int mx = 1e5+1;
int main(){
	int n,k;
	char s[mx], ss[mx];
	scanf("%d %d %s",&n,&k,s);
	rep(i,0,mx) ss[i] = s[i];
	rep(i,0,n){
		if(s[i]-'a' > 'z'-s[i]){
			int d = s[i]-'a';
			if(d >= k){
				ss[i] = s[i]-k;
				k = 0;
				break;
			} else {
				k -= d;
				ss[i] = 'a';
			}
		} else {
			int d = 'z'-s[i];
			if(d >= k){
				ss[i] = s[i]+k;
				k = 0;
				break;
			} else {
				k -= d;
				ss[i] = 'z';
			}
		}
	}
	if(k > 0){
		puts("-1");
	} else {
		printf("%s\n",ss);
	}
}