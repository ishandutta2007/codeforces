# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 1e3+10;
pair <int,int> a[xn];
int b[xn];
 
bool cmp(int q,int w){
	if (q > w) return true;
	return false;
}
 
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].first, a[i].second = i;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (a[i].first >= a[j].first) swap(a[i],a[j]);
		}
	}
	long long ans = 0;
	int t = 0;
	for (int i=n-1; i>=0; i--)
		ans += t*a[i].first+1, t++;
	for (int i=0; i<n; i++)
		b[i] = a[n-i-1].second+1;
	cout << ans << endl;
	for (int i=0; i<n; i++) cout << b[i] << ' ';
}