#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	string s1,s2;
	cin >> s1 >> s2;
	int a=(s1[0]-'0')*600+(s1[1]-'0')*60+(s1[3]-'0')*10+(s1[4]-'0');
	int b=(s2[0]-'0')*600+(s2[1]-'0')*60+(s2[3]-'0')*10+(s2[4]-'0');
	int aa=(a+b)/2;
	if (aa/60<10) cout << 0 << aa/60 << ':';
	else cout << aa/60 << ':';
	if (aa%60<10) cout << 0 << aa%60 << endl;
	else cout << aa%60 << endl;
}