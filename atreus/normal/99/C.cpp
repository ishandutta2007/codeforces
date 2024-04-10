#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000 + 10 + 10;

set<string> s;
int p[7];

string rot(string t){
	for (int i = 0; i < 3; i++)
		swap(t[i], t[i+1]);
	return t;
}

int main(){
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	int n = 6;
	for (int i = 0; i < 6; i++)
		p[i] = i;
	int cnt = 0;
	do{
		string t;
		for (int i = 0; i < n; i++)
			t += a[p[i]];
		if (s.count(t))
			continue;
		for (int i = 0; i < 4; i++){
			t = rot(t);
			s.insert(t);
			swap(t[4], t[5]);
			swap(t[0], t[2]);
			s.insert(t);	
			swap(t[4], t[5]);
			swap(t[0], t[2]);
		}
		swap(t[0], t[4]);
		swap(t[4], t[2]);
		swap(t[2], t[5]);
		for (int i = 0; i < 4; i++){
			t = rot(t);
			s.insert(t);
			swap(t[4], t[5]);
			swap(t[0], t[2]);
			s.insert(t);
			swap(t[4], t[5]);
			swap(t[0], t[2]);
		}
		swap(t[2], t[5]);
		swap(t[4], t[2]);
		swap(t[0], t[4]);

		swap(t[1], t[4]);
		swap(t[4], t[3]);
		swap(t[3], t[5]);
		for (int i = 0; i < 4; i++){
			t = rot(t);
			s.insert(t);
			swap(t[4], t[5]);
			swap(t[0], t[2]);
			s.insert(t);
			swap(t[4], t[5]);
			swap(t[0], t[2]);
		}
		cnt ++;
	}while(next_permutation(p, p + 6));
	cout << cnt << endl;
}