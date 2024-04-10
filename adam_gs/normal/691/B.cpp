#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	if(s.size()%2==1) {
		char p=s[s.size()/2];
		bool ok=false;
		if(p=='A' || p=='o' || p=='O' || p=='Y' || p=='H' || p=='I' || p=='x' || p=='X') ok=true;
		if(p=='w' || p=='W' || p=='T' || p=='U' || p=='V' || p=='v' || p=='M') ok=true;
		if(!ok) {
			cout << "NIE\n";
			return 0;
		}
	}
	rep(i, s.size()/2) {
		char a=s[i], b=s[s.size()-i-1];
		if(a==b) {
			bool ok=false;
			if(a=='A' || a=='o' || a=='O' || a=='Y' || a=='H' || a=='I' || a=='x' || a=='X') ok=true;
			if(a=='w' || a=='W' || a=='T' || a=='U' || a=='V' || a=='v' || a=='M') ok=true;
			if(!ok) {
				cout << "NIE\n";
				return 0;
			}
		} else {
			bool ok=false;
			if(a=='p' && b=='q' || a=='q' && b=='p' || a=='b' && b=='d' || a=='d' && b=='b') ok=true;
			if(!ok) {
				cout << "NIE\n";
				return 0;
			}
		}
	}
	cout << "TAK\n";
}