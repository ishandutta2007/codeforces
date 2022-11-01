#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define INF 1000000000
// hello world :)
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	vi b(k);
	for(int i = 0; i < k; i++)
		cin >> b[i];
	vi l(k);
	vi r(k);
	vi s(k, -1);
	int p = 0;
	for(int i = 0; i < k; i++) {
		l[i] = p;
		int sum = a[p];
		while(p + 1 < n && sum < b[i]) {
			p++;
			sum += a[p];
		}
		if(sum != b[i])
			return cout<<"NO",0;
		r[i] = p;
		p++;
		for(int j = l[i]; j <= r[i]; j++) {
			queue<int> L;
			queue<int> R;
			for(int w = j-1; w >= l[i]; w--)
				L.push(a[w]);
			for(int w = j+1; w <= r[i]; w++)
				R.push(a[w]);
			int v = a[j];
			while(!(L.empty() && R.empty())) {
				int el1 = v;
				if(!L.empty())
					el1 = L.front();
				int el2 = v;
				if(!R.empty())
					el2 = R.front();
				if(v > el1) {
					v += el1;
					L.pop();
				} else if(v > el2) {
					v += el2;
					R.pop();
				} else
					break;
			}
			if(L.empty() && R.empty()) {
				s[i] = j;
				break;
			}
		}
		if(s[i] == -1)
			return cout<<"NO",0;
	}
    if(r[k-1] != n-1)
        return cout<<"NO",0;
	cout << "YES\n";
	for(int i = k-1; i >= 0; i--) {
		int p = s[i];
		queue<int> L;
		queue<int> R;
		for(int w = p-1; w >= l[i]; w--)
			L.push(a[w]);
		for(int w = p+1; w <= r[i]; w++)
			R.push(a[w]);
		int v = a[p];
		while(!(L.empty() && R.empty())) {
			int el1 = v;
			if(!L.empty())
				el1 = L.front();
			int el2 = v;
			if(!R.empty())
				el2 = R.front();
			if(v > el1) {
				v += el1;
				L.pop();
				cout << p+1 << " L\n";
				p--;
			} else if(v > el2) {
				v += el2;
				R.pop();
				cout << p+1 << " R\n";
			}
		}
	}
}