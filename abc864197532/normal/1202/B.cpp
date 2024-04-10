#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
int nums[10][10][10];
int times[10];

void find (int i,int j) {
	fop (a,0,times[i]) {
		fop (b,0,times[j]) {
			if (a==0 and b==0) continue;
			else nums[i][j][(a*i+b*j)%10]=min(nums[i][j][(a*i+b*j)%10],a+b);
		}
	}
}


int main () {
	string s;
	cin >> s;
	times[0]=2;
	fop (i,1,10) times[i]=10/__gcd(i,10)+1;
	fop (i,0,10) {
		fop (j,0,10) {
			fop (k,0,10) nums[i][j][k]=INT_MAX;
			find(i,j);
		}
	}
	int now=0,change;
	int m[10][10];
	fop (i,0,10) {
		fop (j,0,10) {
			m[i][j]=0;
		}
	}
	fop (i,1,s.length()) {
		change=s[i]-'0'-now;
		now=s[i]-'0';
		if (change<0) change+=10;
		fop (j,0,10) {
			fop (k,0,10) {
				if (nums[j][k][change]==INT_MAX) m[j][k]=-1;
				if (m[j][k]==-1) continue;
				m[j][k]+=nums[j][k][change];
				m[j][k]--;
			}
		}
 	}
 	fop (i,0,10) {
 		fop (j,0,10) {
 			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
}