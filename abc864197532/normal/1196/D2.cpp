#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int a[200001],b[200001],c[200001];

char aa[3]={'R','G','B'};

int main () {// RGB
	int t;
	cin >> t;
	for (int i=0;i<t;++i) {
		int n,k,min=1000000;
		cin >> n >> k;
		a[0]=0;
		b[0]=0;
		c[0]=0;
		string s;
		cin >> s;
		for (int i=1;i<=n;++i) {
			a[i]=a[i-1]+1;
			b[i]=b[i-1]+1;
			c[i]=c[i-1]+1;
			if (s[i-1]==aa[(i-1)%3]) a[i]--;
			if (s[i-1]==aa[i%3]) b[i]--;
			if (s[i-1]==aa[(i+1)%3]) c[i]--;
			if (i>=k) {
				if (a[i]-a[i-k]<min) min=a[i]-a[i-k];
				if (b[i]-b[i-k]<min) min=b[i]-b[i-k];
				if (c[i]-c[i-k]<min) min=c[i]-c[i-k];
			}
		}
		cout << min << endl; 
	}
}