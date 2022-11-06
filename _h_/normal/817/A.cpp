#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	a -= c, b -= d;
	int x,y;
	cin >> x >> y;
	puts(a%x==0 && b%y==0 && (a%(2*x)==0)==(b%(2*y)==0) ? "YES" : "NO");
}