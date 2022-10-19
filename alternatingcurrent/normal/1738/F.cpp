#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;

int n, d[1010];
int par[1010];
int getpar(int now){
	return par[now] = par[now] == now ? now : getpar(par[now]);
}
bool done[1010];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n)
			cin >> d[i];
		
		priority_queue< pair<int, int> > pq;
		rep(i, n)
			pq.push(make_pair(d[i], i));
		
		rep(i, n)
			par[i] = i;
		memset(done, 0, sizeof(done));
		
		while(!pq.empty()){
			int np = pq.top().second; pq.pop();
			if(done[np])
				continue;
			
			done[np] = 1;
			rep(i, d[np]){
				cout << "? " << np+1 << endl;
				int to;
				cin >> to;
				--to;
				if(done[to]){
					par[getpar(np)] = getpar(to);
					break;
				} else {
					done[to] = 1;
					par[to] = getpar(np);
				}
			}
		}
		
		cout << "! ";
		rep(i, n)
			cout << getpar(i)+1 << " ";
		cout << endl;
	}
	
	return 0;
}