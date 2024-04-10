#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

bool same(string s, string t){
	if(s.length() != t.length())ret false;
	int n = s.length();
	F(i, 0, n){
		char a = s[i], b = t[i];
		if(isalpha(a))a = tolower(a);
		if(isalpha(b))b = tolower(b);
		if(a == b)cont;
		if(a == '0' && b == 'o')cont;
		if(a == 'o' && b == '0')cont;
		if(a == 'i' && b == 'l')cont;
		if(b == 'i' && a == 'l')cont;
		if(a == '1' && b == 'l')cont;
		if(b == '1' && a == 'l')cont;
		if(a == '1' && b == 'i')cont;
		if(b == '1' && a == 'i')cont;
		ret false;
	}
	ret true;
}

int main(){
	sync;
	string s;
	cin >> s;
	int n;
	cin >> n;
	bool good = true;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		if(same(s, t))good = false;
	}
	if(good)cout << "Yes"; else cout << "No";
	ret 0;
}