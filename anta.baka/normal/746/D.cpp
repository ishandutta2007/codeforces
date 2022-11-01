#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n,k,a,b;
	cin>>n>>k>>a>>b;
	int cg=(a+k-1)/k;
	int cb=(b+k-1)/k;
	if(cg>b+1||cb>a+1)return cout<<"NO",0;

	char now;
	if(a>=b) {
		now='G';
		a--;
		cg--;
		cb=cg;
	}
	else {
		now='B';
		b--;
		cb--;
		cg=cb;
	}
	cout<<now;
	int streak=1;
	for(int i=1; i<n; i++)
		if(now=='G') {
			if(streak==k||a==cg){
				cb--;
				now='B';
				cout<<now;
				b--;
				streak=1;
			} else {
				cout<<now;
				a--;
				streak++;
			}
		} else {
			if(streak==k||b==cb){
				cg--;
				now='G';
				cout<<now;
				a--;
				streak=1;
			} else {
				cout<<now;
				b--;
				streak++;
			}
		}
}