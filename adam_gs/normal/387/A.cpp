#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int decode(string a) {
	return (a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');
}
string encode(int a) {
	int min=a%60; a/=60;
	string ans="";
	ans+=char(a/10+'0');
	ans+=char(a%10+'0');
	ans+=":";
	ans+=char(min/10+'0');
	ans+=char(min%10+'0');
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	int x=decode(a), y=decode(b);
	x=(x-y+1440)%1440;
	cout << encode(x) << '\n';
}