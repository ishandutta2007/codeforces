#include <cstdio>
#include <bitset>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	bitset<500005> seq, res;
	int n, a;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&a);
		seq[i] = bool(a);
	}
	int ans = 0;
	res[0] = seq[0];
	for(int pos = 1; pos < n-1;){
		while(pos < n-1 && (seq[pos-1] == seq[pos] || seq[pos] == seq[pos+1])){
			res[pos] = seq[pos];
			pos++;
		}
		int prev = pos;
		if(pos == n-1)
			continue;
		while(pos < n-1 && seq[pos-1] != seq[pos] && seq[pos] != seq[pos+1])
			++pos;
		ans = max(ans, (pos - prev + 1)/2);
		int m = (prev + pos)/2;
		rep(i,prev,m)
			res[i] = seq[prev-1];
		rep(i,m,pos)
			res[i] = seq[pos];
	}
	res[n-1] = seq[n-1];
	printf("%d\n",ans);
	rep(i,0,n)
		printf("%d ", int(res[i]));
}