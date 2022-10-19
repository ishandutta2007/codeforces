#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e3+7;
struct var {
	int typ, indA, indB;
	string S;
};
vector<var>V;
int T[LIM];
int licz(int x, int p) {
	V[0].S[x]=p+'0';
	rep(i, V.size()) T[i]=0;
	int ans=0;
	rep(i, V.size()) {
		if(V[i].typ==0) T[i]=V[i].S[x]-'0';
		else if(V[i].typ==1) T[i]=T[V[i].indA]&T[V[i].indB];
		else if(V[i].typ==2) T[i]=T[V[i].indA]|T[V[i].indB];
		else T[i]=T[V[i].indA]^T[V[i].indB];
		ans+=T[i];
	}
	return ans-T[0];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<string,int>mp;
	mp["?"]=0;
	string tmp="";
	rep(i, m) tmp+="0";
	V.pb({0, 0, 0, tmp});
	while(n--) {
		string a, b;
		cin >> a >> b >> b;
		mp[a]=V.size();
		if(b[0]=='0' || b[0]=='1') V.pb({0, -1, -1, b});
		else {
			string c, d;
			cin >> c >> d;
			if(c=="AND") V.pb({1, mp[b], mp[d], ""});
			else if(c=="OR") V.pb({2, mp[b], mp[d], ""});
			else if(c=="XOR") V.pb({3, mp[b], mp[d], ""});
		}
	}
	string ans1="", ans2="";
	rep(i, m) {
		int a=licz(i, 0), b=licz(i, 1);
		if(a<=b) ans1+="0";
		else ans1+="1";
		if(a>=b) ans2+="0";
		else ans2+="1";
	}
	cout << ans1 << '\n' << ans2 << '\n';
}