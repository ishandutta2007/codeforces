#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	string s;
	fop (i,0,n) {
		cin >> s;
		int tmp=0;
		fop (i,0,s.length()) {
			if (tmp==0 and s[i]>='0' and s[i]<='9') {
				tmp=1;
			} if (tmp==1 and s[i]>='A' and s[i]<='Z') tmp=2;
		}
		int a=0,b=0,now=0;
		if (tmp==1) {
			fop (i,0,s.length()) {
				if (s[i]>='A' and s[i]<='Z') {
					a=a*26+(s[i]-'A')+1;
				} else {
					b=b*10+s[i]-'0';
				}
			}
			cout << 'R' << b << 'C' << a << endl;
		} else {
			fop (i,0,s.length()) {
				if (s[i]>='0' and s[i]<='9') {
					if (now==0) a=a*10+s[i]-'0';
					else b=b*10+s[i]-'0';
				}
				if (s[i]=='C') now++;
			}
			string c="";
			while (b>0) {
				if (b%26!=0) {
					c+=b%26-1+'A';
					b/=26;
				} else {
					c+='Z';
					b--;
					b/=26;
				}
			}
			reverse(c.begin(),c.end());
			cout << c << a << endl;
		}
	}
}