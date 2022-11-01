# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
int rigt[xn], lft[xn];

int main(){
	string a, b;
	cin >> a >> b;
	int p = 0;
	for (int i=0; i<a.size(); i++)
		if (p < b.size() and a[i] == b[p]) lft[p] = i, p++;
	p = 0;
	for (int i=a.size()-1; i>=0; i--)
		if (p < b.size() and a[i] == b[b.size()-p-1]) rigt[b.size()-p-1] = i, p++;
	int mx = rigt[0];
	rigt[b.size()] = a.size(), lft[b.size()] = lft[b.size()-1]+1;
	for (int i=1; i<b.size(); i++)
		mx = max(mx, rigt[i]-lft[i-1]-1);
	mx = max(mx, rigt[b.size()]-lft[b.size()]);
	cout << mx << endl;
}