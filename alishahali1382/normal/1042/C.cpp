#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200 * 1000 + 10;

int n, m, ind, cnt, tmp;
int A[MAXN];

vector<int> v2, out, rem;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (!A[i]) rem.push_back(i);
		if (A[i]<0) v2.push_back(i);
	}
	int b=v2.size();
	if (b%2){
		tmp=v2[0];
		for (int i=1; i<b; i++){
			if (A[v2[i]]>A[tmp]) tmp=v2[i];
		}
		rem.push_back(tmp);
	}
	//cerr<<rem.size()<<endl;
	for (int i=1; i<rem.size(); i++) cout<<"1 "<<rem[i-1]<<' '<<rem[i]<<endl;
	if (rem.size()!=n && rem.size()) cout<<"2 "<<rem.back()<<endl;
	
	//cerr<<"bug"<<endl;
	for (int i : rem) A[i]=0;
	for (int i=1; i<=n; i++) if (A[i]) out.push_back(i);
	//cerr<<out.size();
	//cerr<<"bug"<<endl;
	
	if (out.size()>=2) for (int i=0; i<out.size()-1; i++) cout<<"1 "<<out[i]<<' '<<out[i+1]<<endl;
	

	
	return 0;
}