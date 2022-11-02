#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;
int n;
int a[5555];
int cnt[5555];
int cur[5555];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++)
			cur[j] = 0;
	 	int mx = 0, ind = 0;
	 	for(int j = i; j < n; j++){
	 		cur[a[j]]++;
	 		if(cur[a[j]] > mx){
	 			mx = cur[a[j]];
	 			ind = a[j];
	 		}
	 		else if(mx == cur[a[j]] && a[j] < ind){
	 			ind = a[j];
	 		}
	 		cnt[ind]++;
	 	}
	}
	for(int i = 1; i <= n; i++)
		cout<<cnt[i]<<" ";
	
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}