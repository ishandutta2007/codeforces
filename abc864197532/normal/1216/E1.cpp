#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

lli sumTo (lli k) {
	return k*(k+1)/2;
}

lli value (int a) {
	lli sum=9;
	fop (i,1,a) sum*=10;
	return sum;
}


lli sum (lli n) {
	int now=1,tmp=1;
	lli ans=0;
	while (now<=n) {
		ans+=tmp*sumTo(min(n-now+1,value(tmp)));
		ans+=max(n-now*10+1,0ll)*value(tmp)*tmp;
		now*=10;
		tmp++;
	}
	return ans;
}

int find (int n) {
	int a=0,now=9,tmp=1;
	while (true) {
		if (n>=now*tmp) {
			n-=now*tmp;
			a+=now;
		} else {
			int k=n/tmp;
			a+=k;
			n%=tmp;
			break;
		}
		now*=10;
		tmp++;
	}
	if (n==0) return a%10;
	a++;
	fop (i,0,tmp-n) {
		a/=10;
	}
	return a%10; 
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		lli n;
		cin >> n;
		int l=0,r=20000000,m;
		while (r-l!=1) {
			m=(l+r)>>1;
			if (sum(m)>n) r=m;
			else l=m;
		}
		n-=sum(l);
		if (n==0) cout << l%10 << endl;
		else cout << find(n) << endl;
	}
}