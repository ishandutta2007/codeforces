#include <bits/stdc++.h>

using namespace std;

int n;
string s[100000];
int type[100000];
int e;
int NUM[100000];
vector<string> X, Y;

inline string STR(int n) {
	string ret;
	while(n) {
		ret.push_back(char('0' + n % 10));
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> type[i];
		e += (type[i] == 1);
	}
	vector<bool> used(n + 1, false);
	vector<int> bad0, bad1, hz;
	for(int i = 0; i < n; i++)
		{
			bool ok = true;
			for(char x : s[i])
				ok &= isdigit(x);
			if(!ok || s[i][0] == '0') { hz.push_back(i); continue; }
			int num = 0;
			for(char x : s[i])
				num = num * 10 + (x - '0');
			if(type[i] == 1 && e + 1 <= num && num <= n) {
				bad1.push_back(i);
				NUM[i] = num;
				used[num] = true;
			} else if(type[i] == 0 && 1 <= num && num <= e) {
				bad0.push_back(i);
				NUM[i] = num;
				used[num] = true;
			} else if(type[i] == 0 && e + 1 <= num && num <= n || type[i] == 1 && 1 <= num && num <= e) {
				NUM[i] = num;
				used[num] = true;
			} else
				hz.push_back(i);
		}
	if(bad0.empty() && bad1.empty() && hz.empty()) {
		cout << 0;
		return 0;
	}
	vector<int> places0, places1;
	for(int i = 1; i <= e; i++)
		if(!used[i])
			places1.push_back(i);
	for(int i = e + 1; i <= n; i++)
		if(!used[i])
			places0.push_back(i);
	int I = -1;
	string ASS = "pdfknz"; // !!!!!
	if(hz.empty()) {
		I = bad0.back();
		bad0.pop_back();
		places1.push_back(NUM[I]);
		X.push_back(s[I]);
		Y.push_back(ASS);
	}
	while(true)
		if(!places0.empty() && !bad0.empty()) {
			int pos = places0.back();
			places0.pop_back();
			int i = bad0.back();
			bad0.pop_back();
			X.push_back(s[i]);
			Y.push_back(STR(pos));
			places1.push_back(NUM[i]);
		} else if(!places1.empty() && !bad1.empty()) {
			int pos = places1.back();
			places1.pop_back();
			int i = bad1.back();
			bad1.pop_back();
			X.push_back(s[i]);
			Y.push_back(STR(pos));
			places0.push_back(NUM[i]);
		} else break;
	if(I != -1) {
		X.push_back(ASS);
		Y.push_back(STR(places0.back()));
		places0.pop_back();
	}
	while(!hz.empty()) {
		int i = hz.back();
		hz.pop_back();
		if(type[i] == 0) {
			int pos = places0.back();
			places0.pop_back();
			X.push_back(s[i]);
			Y.push_back(STR(pos));
		} else {
			int pos = places1.back();
			places1.pop_back();
			X.push_back(s[i]);
			Y.push_back(STR(pos));
		}
	}
	cout << X.size() << '\n';
	for(int i = 0; i < X.size(); i++)
		cout << "move " << X[i] << ' ' << Y[i] << '\n';
}