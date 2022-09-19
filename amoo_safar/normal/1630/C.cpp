#include<bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 5e5 + 10;


int fs[N], la[N], mt[N];
int A[N];

int Main(){
	
	memset(la, -1, sizeof la);
	memset(mt, -1, sizeof mt);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) la[A[i]] = i;
	for(int i = 0; i < n; i++) fs[A[n-1-i]] = n-1-i;
	vector< pair<int, int> > V;
	for(int x = 1; x <= n; x ++){
		if(la[x] == -1) continue;
		V.pb({fs[x], la[x]});
//		cerr << "## " << fs[x] << ' ' << la[x] << '\n';
		mt[fs[x]] = la[x];
	}
	sort(V.begin(), V.end());
	int pw = -1;
	int mx = -1;
	int ans = 0;
	
	for(int i = 0;i < n; i++){
//		cerr << "!! " << ans << '\n';
		if(mt[i] != -1){
//			cerr << i << '\n';
			if(i > pw){
				pw = mt[i];
				mx = mt[i];
				ans += 1 + (mt[i] != i);
			}
			mx = max(mx, mt[i]);
		}
		if(i == pw){
			if(mx > pw) ans ++;
			pw = max(pw, mx);
		}
//		cerr << "?? " << ans << "\n\n";
	}
	cout << n - ans << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int t = 1;
//	cin >> t;
	while(t --) Main();
	return 0;
}