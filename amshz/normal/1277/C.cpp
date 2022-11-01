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
 
int main(){
	int qq;
	cin >> qq;
	while (qq--){
		string a;
		cin>>a;
		int n = a.size();
		int ans = 0;
		vector <int> v;
		for (int i=0; i<n-2;){
			if (a[i] == 't'){
				if (a[i+1] == 'w' && a[i+2] == 'o'){
					if (i < n-4 && a[i+3] == 'n' && a[i+4] == 'e'){
						ans++;
						v.pb(i+3);
						i += 4;
					}
					else{
						ans++;
						v.pb(i+2);
						i += 2;
					}
				}
			}
			else if (a[i] == 'o' && a[i+1] == 'n' && a[i+2] == 'e'){
				ans++;
				v.pb(i+2);
				i += 2;
			}
			i++;
			
		}
		cout<< ans<<endl;
		for (int i=0;i<v.size();i++) cout<< v[i]<<sep;
		cout<<endl;
	}
}