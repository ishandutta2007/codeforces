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

const ll MAXN = 1500 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , mark[MAXN] , row[MAXN] , cnt[MAXN] , A[MAXN][MAXN] , B[MAXN][MAXN] , P1[MAXN] , P2[MAXN];
vector<int> vec[MAXN] , vec2[MAXN];

int cmp1(int x , int y){
	for(int i = 0 ; i <= m ; i++){
		if(A[x][i] < A[y][i])	return 1;
		if(A[y][i] < A[x][i])	return 0;
	}
}

int cmp2(int x , int y){
	for(int i = 0 ; i <= m ; i++){
		if(B[x][i] < B[y][i])	return 1;
		if(B[y][i] < B[x][i])	return 0;
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> A[i][j];
		}
		A[i][m] = i;
		P1[i] = i;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> B[i][j];
		}
		B[i][m] = i;
		P2[i] = i;
	}
	sort(P1 , P1 + n , cmp1);
	sort(P2 , P2 + n , cmp2);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(A[P1[i]][j] != B[P2[i]][j]){
				cout << -1 << endl;
				return 0;
			}
		}
		row[B[P2[i]][m]] = A[P1[i]][m];
	}
//	for(int i = 0 ; i < n ; i++)	cout << row[i] << endl;
	for(int i = 0 ; i + 1 < n ; i++){
		int x = row[i] , y = row[i + 1];
		mark[i] = 1;
		for(int j = 0 ; j <= m ; j++){
			if(A[x][j] == A[y][j])	continue;
			if(A[x][j] < A[y][j]){
				vec[j].push_back(i);
				continue;
			}
			cnt[j]++;
			vec2[i].push_back(j);
		}
	}
	queue<int> q;
	vector<int> ans;
	for(int i = 0 ; i <= m ; i++){
		if(cnt[i] == 0)	q.push(i);
	}
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i : vec[v]){
			if(mark[i] == 0)	continue;
			mark[i] = 0;
			for(int j : vec2[i]){
				cnt[j]--;
				if(cnt[j] == 0){
					q.push(j);
				}
			}
		}
		if(v == m)	break;
		ans.push_back(v + 1);
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i])	return cout << -1 << endl , 0;
	}
	cout << SZ(ans) << endl;
	reverse(all(ans));
	for(int i : ans)	cout << i << sep;

    return 0;
}
/*

*/