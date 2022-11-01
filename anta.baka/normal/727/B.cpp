#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head


int bef = 0, aft = 0;

void add(string s) {
	int n = sz(s);
	vector<int> del;
	for(int i = 0; i < n; i++)
		if(s[i] == '.')
			del.pb(i);
	if(!del.empty() && del.back() == n-3) {
		aft += (s[n-2]-'0')*10+(s[n-1]-'0');
		del.pop_back(); s.erase(n-3);
	}
	for(int i = sz(del)-1; i >= 0; i--)
		s.erase(del[i],1);
	int r = 0; n = sz(s);
	for(int i = 0; i < n; i++)
		r = r*10 + (s[i]-'0');
	bef += r;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	string s; cin >> s;
	int n = sz(s);
	for(int i = 0; i < n; i++)
		if(!isalpha(s[i])) {
			int j = i;
			while(j < n-1 && !isalpha(s[j+1]))
				j++;
			add(s.substr(i,j-i+1));
			i = j;
		}
	bef += aft / 100;
	aft %= 100;
	vector<int> ou;
	if(bef == 0)
		ou.pb(0);
	else
		while(bef) {
			ou.pb(bef%10); bef /= 10;
		}
	reverse(all(ou));
	n = sz(ou);
	for(int i = 0; i < n; i++) {
		cout << ou[i];
		if(n-i-1!=0 && (n - i - 1) % 3 == 0)
			cout << '.';
	}
	if(aft) {
		cout << '.';
		if(aft < 10)
			cout << 0;
		cout <<aft;
	}
}