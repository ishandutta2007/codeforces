#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int compare(string s,int a,int n) {
	fop (i,0,n) {
		if (s[i]>s[a*n+i]) return 1;
		if (s[i]<s[a*n+i]) return -1;
	}
	return 0;
}

string add (string s,int n) {
	char c[n];
	fop (i,0,n) c[i]=s[i];
	int now=n-1;
	while (c[now]=='9' and now!=-1) {
		c[now]='0';
		now--;
	}
	string ss="";
	if (now==-1) return ss;
	c[now]++;
	fop (i,0,n) ss+=c[i];
	return ss;
}


int main () {
	int n;
	string s;
	cin >> n >> s;
	if (s.length()%n!=0) {
		fop (i,0,s.length()/n+1) {
			cout << 1;
			fop (j,1,n) cout << 0;
		}
	} else {
		bool is=true,iss=false;
		fop (i,1,s.length()/n) {
			int aa=compare(s,i,n);
			if (aa==-1) is=false;
			else if (aa==1) iss=true;
		}
		if (is && iss) {
			fop (i,0,s.length()/n) {
				fop (j,0,n) cout << s[j];
			}
		} else {
			string ss=add(s,n);
			if (ss!="") {
				fop (i,0,s.length()/n) cout << ss;
			} else {
				fop (i,0,s.length()/n+1) {
					cout << 1;
					fop (j,1,n) cout << 0;
				}
			}
		}
	}
	cout << endl;
}