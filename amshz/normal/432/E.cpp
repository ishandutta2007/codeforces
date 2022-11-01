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
const int xn = 1e2+10;
 
char a[xn][xn];
int n, m;
 
ll check(int x, int y, char ch){
	if (a[x-1][y] == ch)	return -1;
	if (a[x][y+1] == ch)	return -1;
	ll flag = 0;
	for (int i = y-1; i >= 1; --i){
	  	if (a[x][i] == ch){
	 		++flag;
	 	}
	 	else	break;
	}
	 if (x+flag > n)	return -1;
	 return flag;
}
 
int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (a[i][j] == char(0)){
				//cout << i  << sep << j << endl;
				for (int k = 0; k < 4; ++k){
					char ch1 = char('A'+k);
					ll flag = check(i, j, ch1);
					if (flag  == -1)	continue;
					//cout << ch1 << sep << flag << endl;
					for (int l = i; l <= i+flag; ++l)	a[l][j] = ch1;
					for (int l = j; l >= j-flag; --l)	a[i+flag][l] = ch1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j)	cout << a[i][j];
		cout << endl;
	}
}