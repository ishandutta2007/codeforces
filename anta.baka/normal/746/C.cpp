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

	int s,x1,x2;
	int t1,t2;
	int p,d;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	int igor=abs(x1-x2)*t2;
	int tram = abs(x1-x2)*t1;
	if(x1<x2) {
		if(p<=x1) {
			tram += abs(p-x1)*t1;
			if(d==-1)tram += 2*p*t1;
		} else {
			if(d==1)tram += t1*abs(s-p+s+x1);
			else tram+=t1*abs(p+x1);
		}
	} else {
		if(p>=x1) {
			tram += abs(p-x1)*t1;
			if(d==1)tram += 2*(s-p)*t1;
		} else {
			if(d==1)tram += t1*abs(s-p+s-x1);
			else tram+=t1*abs(p+s+s-x1);
		}
	}
	cout << min(igor,tram);
}