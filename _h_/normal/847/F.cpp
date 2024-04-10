#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k,m,a;
	cin >> n >> k >> m >> a;
	vi tot(n), lst(n,-1);
	rep(i,0,a){
		int g;
		cin >> g;
		--g;
		++tot[g];
		lst[g] = i;
	}
	vector<pii> ls(n);
	rep(i,0,n) ls[i] = {tot[i], -lst[i]};
	sort(all(ls));
	reverse(all(ls));
	if(m==a){
		rep(i,0,n){
			if(tot[i] && pii(tot[i],-lst[i])>=ls[k-1])
				cout << 1 << ' ';
			else
				cout << 3 << ' ';
		}
	} else {
		if(k==n){
			rep(i,0,n){
				if(tot[i])
					cout << "1 ";
				else cout << "2 ";
			}
		} else {
			rep(i,0,n){
				if(pii(tot[i],-lst[i])>ls[k]){
					int j = 0;
					while(ls[j].second != -lst[i]) ++j;
					int cur = 0;
					rep(x,j+1,k+1)
						cur -= -1 + ls[x].first - ls[j].first;
					if(cur > m-a)
						cout << "1 ";
					else
						cout << "2 ";
				} else {
					if(ls[k-1].first-tot[i]+1 > m-a)
						cout << "3 ";
					else
						cout << "2 ";
				}
			}
		}
	}
	cout << endl;
}