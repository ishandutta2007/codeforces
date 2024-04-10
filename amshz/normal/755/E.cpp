# include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

# define endl '\n'
# define sep ' '
# define pb push_back
# define F first
# define S  second

int main(){
	int n, k;
	cin >> n >> k;
	
	if (k < 2 || k > 3 || n < 4 ){
		cout << -1 << endl;
		return 0;
	}
	if (k == 2){
		if (n == 4){
			cout << -1 << endl;
			return 0;
		}
		cout << n-1 << endl;
		for (int i=1; i<n; i++) cout << i << sep << i+1 << endl;
	}
	
	else{
		cout << 2*n-5  << endl;
		for (int i=2; i<n-1; i++) cout << 1 << sep << i << endl;
		for (int i=3; i<n-1; i++) cout << 2 << sep << i << endl;
		cout << 2 << sep << n-1 << endl;
		cout << n-1 << sep << n << endl;
	}
}