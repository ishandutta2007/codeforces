#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define forit(it, v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)

typedef pair <int, int > pii;
typedef vector <int> vi;
typedef long long ll;

int n;
int k;
int a[6][100100];

int tb[6][22][100100];
int lg[200010];
int m;



void process(){
	lg[0] = -1;
	for(int i = 1; i<= n + n; i++)
		lg[i] = lg[i/2] + 1;
	for(int i = 0;  i< n; i++){
		for(int j = 0; j < m; j++)
			tb[j][0][i] = a[j][i];
	}
	for(int k=1; (1 << k) <= n; k++){
		for(int i = 0; i + (1 << k) <= n; i++){
			for(int j = 0; j < m; j++){
				tb[j][k][i] = max(tb[j][k-1][i], tb[j][k-1][i + (1 << (k-1))]);
			}
		}
	}
}

int getmax(int l, int r, int j){
	int len = lg[r-l+1];
	return max(tb[j][len][l], tb[j][len][r-(1 << len)+1]);
}

int check(int len){
	int mx = k+10;
	for(int i = 0; i+len <= n; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			sum += getmax(i, i+len-1, j);
		}
		mx = min(mx, sum);
	}
	return mx;
} 




int main(){
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	cin>>n >> m >> k;
	for(int i=0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[j][i];
	process();
	int l = 1;
	int r = n;
	int ans=0;

	//cout << getmax(0, 2, 0) << " " << getmax(0, 2, 1) << endl;

	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid) <= k){
			l = mid+1;
			//cout << mid << " "  << check(mid) << endl;
			ans = mid;
		}
		else {
			r = mid-1;	
		}
	}
	//cout << ans << endl;
	if(!ans){
		for(int i = 0;  i<m; i++)
			cout << "0 ";
		return 0;
	}
	for(int i = 0; i + ans<= n; i++){
		int sum = 0;
		for(int j=0; j<m; j++){
			sum += getmax(i, i+ans-1, j);
		}
		if(sum <= k){
			for(int j=0; j < m; j++){
				cout << getmax(i, i+ans-1, j) <<" ";
			}
			cout << endl;
			return 0;
		}
	}



	#ifdef LOCAL
	cerr << 1.0 * clock()/CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}