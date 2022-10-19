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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , P[MAXN];
vector<int> vec , v;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> P[i];
	vec.push_back(1);
	for(int i = 2 ; i < n ; i++){
		if(P[i - 1] < P[i] && P[i + 1] < P[i])	vec.push_back(i);
		if(P[i - 1] > P[i] && P[i + 1] > P[i])	vec.push_back(i);
	}
	vec.push_back(n);
	for(int i = 1 ; i < SZ(vec) ; i++)	v.push_back(vec[i] - vec[i - 1]);
	pii mx = {0 , 0};
	int flag = 0;
	for(int i = 0 ; i < SZ(v) ; i++){
		pii A = {v[i] , (i + (P[1] > P[2])) / 2};
		if(A == mx){
			flag = 2;
			continue;
		}
		if(A.X == mx.X){
			flag = 1;
			continue;
		}
		if(A.X > mx.X){
			mx = A;
			flag = 0;
		}
	}
	if(flag != 2)	return cout << 0 << endl , 0;
	cout << 1 - mx.X % 2 << endl;

    return 0;
}
/*

*/