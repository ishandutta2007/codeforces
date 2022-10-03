#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=2000 * 1000 + 10;

int a, b, c, bb, cc;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>a>>b>>c;
	for (int i=0; i<=a; i++){
		bb=b-i;
		cc=c-(a-i);
		if (bb==cc && (bb>0 || !bb && i && (a-i))){
			cout<<i<<' '<<bb<<' '<<a-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}