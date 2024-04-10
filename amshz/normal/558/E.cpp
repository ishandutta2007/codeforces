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
const int xn = 1e5+10;
const int xm = 3e1+10;
const int SQ = 500;
const ll inf = 1e9+10;

int a[xn], b[xn], c[xn][xm], n, q, d[xm], x, y, z;
string s;

int get(int l, int r, int x){
	int ans = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (b[i/SQ] == x) ans += SQ;
			else if (b[i/SQ] == -1) ans += c[i/SQ][x];
			i += SQ;
		}
		else{
			if (b[i/SQ] == x) ans++;
			else if (b[i/SQ] == -1 && a[i] == x) ans++;
			i++;
		}
	}
	return ans;
}
void get_all(int l, int r){
	for (int i = 0; i < 26; i++) d[i] = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (b[i/SQ] != -1) d[b[i/SQ]] += SQ;
			else{
				for (int j = 0; j < 26; j++) d[j] += c[i/SQ][j];
			}
			i += SQ;
		}
		else{
			if (b[i/SQ] != -1) d[b[i/SQ]]++;
			else d[a[i]]++;
			i++;
		}
	}
}
void update(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			b[i/SQ] = x;
			i += SQ;
		}
		else{
			for (int j = 0; j < 26; j++) c[i/SQ][j] = 0;
			for (int j = i-i%SQ; j <= i-i%SQ+SQ-1; j++){
				if ((j >= l && j <= r)) a[j] = x, c[i/SQ][x]++;
				else if (b[i/SQ] != -1) a[j] = b[i/SQ], c[i/SQ][b[i/SQ]]++;
				else c[i/SQ][a[j]]++;
			}
			b[i/SQ] = -1;
			i = i-i%SQ+SQ;
		}
	}
}
void query1(int l, int r){
	get_all(l, r);
	int sm = 0;
	for (int i = 0; i < 26; i++){
		update(l+sm, l+sm+d[i]-1, i);
		sm += d[i];
	}
}
void query2(int l, int r){
	get_all(l, r);
	int sm = 0;
	for (int i = 25; i >= 0; i--){
		update(l+sm, l+sm+d[i]-1, i);
		sm += d[i];
	}
}
char find(int ind){
	for (int i = 0; i < 26; i++) if (get(ind, ind, i)) return char('a'+i);
}

 
int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	fast_io;
	
	cin >> n >> q >> s;
	
	for (int i = 0; i <= 1e5; i++) b[i] = -1;
	for (int i = 0; i < n; i++) a[i] = s[i]-'a', c[i/SQ][a[i]]++;
	
	
	while (q--){
		cin >> x >> y >> z;
		x--, y--;
		if (z) query1(x, y);
		else query2(x, y);
	}
	
	for (int i = 0; i < n; i++) cout << find(i);
	cout << endl;
	
	return 0;
}