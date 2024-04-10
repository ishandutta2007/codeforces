# include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int sa = a.size(), sb = b.size();
	int t = 0;
	
	for (int i=0; i<sb; i++)
		if (a[i] == '1') t++;
	
	int ans = 0;
	if (t%2 == 0) ans++;
	
	for (int i=sb; i<sa; i++){
		if (a[i] == '1') t++;
		if (a[i-sb] == '1') t--;
		if (t%2 == 0) ans++;
	}
	
	t = 0;
	for (int i=0; i<sb; i++)
		if (b[i] == '1') t++;
	
	if (t%2 == 0) cout << ans << endl;
	else cout << sa-sb+1-ans << endl;
}