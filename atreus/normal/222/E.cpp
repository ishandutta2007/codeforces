#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mod = 1e9 + 7;
map<char,int> mp;
int answer, m;

struct matrix{
	int a[55][55];
	matrix operator * (const matrix &y) const{
		matrix ret;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				ret.a[i][j] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < m; k++)
					ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][k] * y.a[k][j]) % mod;
		return ret;
	}
};

matrix power(matrix a, ll b){
	if (b == 1)
		return a;
	matrix c = power(a, b / 2);
	c = c * c;
	if (b & 1)
		c = c * a;
	return c;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	int k;
	cin >> n >> m >> k;
	for (int i = 0; i < 26; i++){
		mp[(char)i + 'a'] = i;
		mp[(char)i + 'A'] = i + 26;
	}
	matrix x;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			x.a[i][j] = 1;
	for (int i = 0; i < k; i++){
		string s;
		cin >> s;
		x.a[mp[s[0]]][mp[s[1]]] = 0;
	}
	if (n == 1)
		return cout << m << '\n', 0;
	x = power(x, n - 1);
	int answer = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			answer = (answer + x.a[i][j]) % mod;
	cout << answer << '\n';
}