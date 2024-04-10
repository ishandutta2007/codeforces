# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 4e5+10;
int a[xn], n, k, c[xn], ans;
vector <int> b[xn];

set<pii> st;

int main(){
	cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[a[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) b[i].pb(n + i);
	
	for (int i = 0; i < n; i++){
		c[a[i]]++;
		//cout << st.size() << sep << a[i] << endl;
		if (st.size() < k){
			//cout << "Eshaq e Khar" << endl;
			if (st.find({2 * n - b[a[i]][c[a[i]] - 1] , a[i]}) == st.end()){
				ans++;
				st.insert({2 * n - b[a[i]][c[a[i]]] , a[i]});
				//cout << "Shit" << endl;
			}
			else{
				st.erase({2 * n - b[a[i]][c[a[i]] - 1] , a[i]});
				st.insert({2 * n - b[a[i]][c[a[i]]] , a[i]});
			}
		}
		else{
			//cout << "Kir to Soroush" << endl;
			if (st.find({2 * n - b[a[i]][c[a[i]] - 1] , a[i]}) != st.end()){
				st.erase({2 * n - b[a[i]][c[a[i]] - 1] , a[i]});
				st.insert({2 * n - b[a[i]][c[a[i]]] , a[i]});
			}
			else{
				ans++;
				st.erase(st.begin());
				st.insert({2 * n - b[a[i]][c[a[i]]] , a[i]});
			}
		}
	}
	
	cout << ans << endl;
}