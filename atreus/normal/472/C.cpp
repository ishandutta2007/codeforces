#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

string s[maxn], k[maxn];
int p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> s[i] >> k[i];
	bool maxx = true, minn = true;
	for(int i=1;i<=n;i++){
		bool Maxx = false, Minn = false;
		cin >> p[i];
		if(maxx == true and max(s[p[i-1]], k[p[i-1]]) < min(s[p[i]], k[p[i]]))
			Minn = true;
		if(maxx == true and max(s[p[i-1]], k[p[i-1]]) < max(s[p[i]], k[p[i]]))
			Maxx = true;
		if(minn == true and min(s[p[i-1]], k[p[i-1]]) < min(s[p[i]], k[p[i]]))
			Minn = true;
		if(minn == true and min(s[p[i-1]], k[p[i-1]]) < max(s[p[i]], k[p[i]]))
			Maxx = true;
		minn = Minn, maxx = Maxx;
	}
	if(minn or maxx)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}