#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

bool bigger(pair <int,int> a,pair<int,int> b) {
	int d,e,f,g;
	tie(d,e)=a;
	tie(f,g)=b;
	if (d>f) return true;
	if (d==f and e<g) return true;
	return false;
}


int main () {
	int n,k,tmp;
	cin >> n >> k;
	vector <pair<int,int> > nums;
	fop (i,0,n) {
		cin >> tmp;
		int k=0;
		while (tmp>0) {
			nums.eb(tmp,k);
			k++;
			tmp/=2;
		}
	}
	sort(nums.begin(),nums.end(),bigger);
	int now=0,no=-100,num=0,t1,t2,minn=INT_MAX;
	fop (i,0,nums.size()) {
		tie(t1,t2)=nums[i];
		if (no!=t1) {
			now=1;
			no=t1;
			num=t2;
		} else {
			now++;
			num+=t2;
		}
		if (now==k) minn=min(minn,num);
	}
	cout << minn << endl;
}