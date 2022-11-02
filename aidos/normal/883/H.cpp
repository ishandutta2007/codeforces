#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"


int n;
char c[400400];

bool ok(vector<pair<char, int> > &v, int x){
	int cc = 0;
	int len = n/x;	
	for(int i = 0; i < v.size(); i++){
		if(v[i].s % 2 == 1 && len % 2 == 0) return 0; 
	}
	for(int i = 0; i < v.size(); i++){
		if(v[i].s % 2 == 1) x--;
	}
	if(x < 0) return false;
	return true;
}

void get(vector<pair<char, int> > &v, int x){
	string ans="";
	string ans2 = "";
	int d = x/2;
	for(int i = 0; i < v.size(); i++){
		while(v[i].s >= 2 && d > 0){
			ans += v[i].f;
			v[i].s-=2;
			d--;
		}
	}
	ans2 = ans;
	reverse(ans2.begin(), ans2.end());
	if(x % 2 == 1){
		for(int i = 0; i < v.size(); i++){
			if(v[i].s % 2 == 1){
				v[i].s--;
				ans+=v[i].f;
				x--;
				break;
			}
		}
	}
	if(x % 2 == 1){
		for(int i = 0; i < v.size(); i++){
			if(v[i].s >0){
				v[i].s--;
				ans+=v[i].f;
				x--;
				break;
			}
		}
	}
	ans += ans2;
	printf("%s", ans.c_str());

}
int main()

{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif
	scanf("%d%s", &n, c);
	map<char, int>M;
	for(int i = 0; i < n; i++){
		M[c[i]]++;
	} 
	vector<pair<char, int> > v(M.begin(), M.end());
	int x=n;
	for(int i = 1; i <= n; i++){
		if(n % i == 0 && ok(v, i)){
			x = i;
			break;
		}
	}
	printf("%d\n", x);
	for(int i =  0; i < x; i++){
		if(i > 0) printf(" ");
		get(v, n/x);
	}
	printf("\n");


	
	return 0;
}