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
 
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}
 
const int xn = 2e5+10;
const int xk = 10;
 
map <string, int> cnt;
string d[xn];
 
string rev(string a){
	string b = "";
	for (int i=a.size()-1; i>=0; i--) b += a[i];
	return b;
}
 
int main(){
	fast_io;
	int k = 0;
	for (int i=0; i<1e3; i++) k++;
	int qq;
	cin>>qq;
	while (qq--){
		cnt.clear();
		int n;
		cin>> n;
		for (int i=0; i<n; i++){
			cin>> d[i];
			cnt[d[i]]++;
		}
		vector <int> v[5];
		int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		for (int i=0; i<n; i++){
			string a = d[i];
			int s = a.size()-1;
			if (a[0] == '0' && a[s] == '0') t1++, v[1].pb(i+1);
			else if (a[0] == '0' && a[s] == '1') t2++, v[2].pb(i+1);
			else if (a[0] == '1' && a[s] == '0') t3++, v[3].pb(i+1);
			else t4++, v[4].pb(i+1);
		}
		if (t1 && t4 && !t2 && !t3){
			cout << -1 << endl;
			continue;
		}
		vector <int> s;
		if (t2 > t3){
			for (int i=0; i<v[2].size(); i++){
				if (t2-t3 < 2) break;
				if (!cnt[rev(d[v[2][i]-1])]){
					t2 -= 2;
					s.pb(v[2][i]);
				}
			}
			if (t2-t3 > 1){
				cout<< -1 << endl;
				continue;
			}
			cout<< s.size() << endl;
			for (int i=0; i<s.size(); i++) cout<< s[i]<<sep;
			cout << endl;
			continue;
		}
		if (t3 >= t2){
			for (int i=0; i<v[3].size(); i++){
				if (t3-t2 < 2) break;
				if (!cnt[rev(d[v[3][i]-1])]){
					t3 -= 2;
					s.pb(v[3][i]);
				}
			}
			if (t3-t2 > 1){
				cout<< -1 << endl;
				continue;
			}
			cout<< s.size() << endl;
			for (int i=0; i<s.size(); i++)cout<<s[i]<<sep;
			cout << endl;
			continue;
		}
		
	}
}