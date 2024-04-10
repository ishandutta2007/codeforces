#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , B[MAXN];

int check(int x){
	vector<int> v , u;
	for(int i = 0 ; i < x ; i++){
		v.push_back(A[i]);
		u.push_back(B[i]);
	}
	sort(all(v) , greater<int>());
	sort(all(u) , greater<int>());
	int s1 = 0 , s2 = 0;
	for(int i = 0 ; i < x - x / 4 ; i++){
		s1 += v[i];
		s2 += u[i];
	}
	return (s1 >= s2);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(A , A + n + n + 10 , 100);
		fill(B , B + n + n + 10 , 0);
		for(int i = 0 ; i < n ; i++)	cin >> A[i];
		for(int i = 0 ; i < n ; i++)	cin >> B[i];
		int l = n - 1 , r = n + n + 5;
		while(r - l > 1){
			int mid = l + r >> 1;
			if(check(mid))	r = mid;
			else	l = mid;
		}
		cout << r - n << endl;
	}

    return 0;
}
/*

*/