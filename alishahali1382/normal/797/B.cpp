#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=100000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 100010;

ll n, ans, tmp, cnt;
ll A[MAXN];

bool cmp(ll a, ll b){
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>tmp;
		if (tmp%2){
			A[cnt++]=tmp;
			continue ;
		}
		if (tmp>0) ans+=tmp;
	}
	sort(A, A+cnt, cmp);
	ans+=A[0];
	ll out=ans;
	for (int i=1; i<cnt; i++){
		ans+=A[i];
		if (ans%2) out=max(out, ans);
	}
	cout<<out<<endl;
	return 0;
}