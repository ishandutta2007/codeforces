#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1024, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool good[MAXN];

void reset(){
	cout<<"R"<<endl;
}
bool ask(int x){
	cout<<"? "<<x+1<<endl;
	char tmp;
	cin>>tmp;
	return (tmp=='Y');
}

void found(int x){
	cout<<"! "<<x<<endl;
	exit(0);
}

void shit(int x, int y){
	for (int i=x; i<x+k/2; i++) if (good[i]) ask(i);
	for (int i=y; i<y+k/2; i++) if (good[i]){
		if (ask(i)) good[i]=0;
	}
	for (int i=x+k/2; i<x+k; i++) if (good[i]){
		if (ask(i)) good[i]=0;
	}
	reset();
	for (int i=x+k/2; i<x+k; i++) if (good[i]) ask(i);
	for (int i=y+k/2; i<y+k; i++) if (good[i]){
		if (ask(i)) good[i]=0;
	}
	for (int i=x; i<x+k/2; i++) if (good[i]){
		if (ask(i)) good[i]=0;
	}
	reset();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	if (n==1) found(1);
	if (k==1){
		for (int i=0; i<n; i++){
			good[i]=1;
			for (int j=0; j<i && good[i]; j++){
				ask(j);
				if (ask(i)) good[i]=0;
				reset();
			}
			ans+=good[i];
		}
		found(ans);
	}
	
	for (int i=0; i<n; i+=k){
		for (int j=i; j<i+k; j++){
			bool tmp=ask(j);
			if (!tmp) good[j]=1;
		}
		reset();
	}
	for (int i=0; i<n; i+=k) for (int j=0; j<i; j+=k) shit(j, i);
	for (int i=0; i<n; i++) ans+=good[i];
	found(ans);
	
	return 0;
}