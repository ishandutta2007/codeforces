
// Problem : E. Aquarium decoration
// Contest : Codeforces - Playrix Codescapes Cup (Codeforces Round #413, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/799/problem/E
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[200005];
int msk[200005];
int who[200005];
pair<int, int> srt[200005];
vector<int> v[4];
long long bitv[200005];
int bitc[200005];
priority_queue<int> pq;

void upd(int n, int coe){
	int v = srt[n].first;
	while(n <= N){
		bitc[n] += coe;
		bitv[n] += coe*v;
		n += n&-n;
	}
}

long long clmb(int n){
	long long ret = 0, idx = 0, cnt = 0;
	for(int d = 18; d>=0; d--){
		if((1<<d)+idx <= N && bitc[(1<<d)+idx]+cnt <= n){
			ret += bitv[(1<<d)+idx];
			cnt += bitc[(1<<d)+idx];
			idx += (1<<d);
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		srt[i] = {arr[i], i};
	}
	sort(srt+1, srt+1+N);
	int S = N;
	for(int i = 1; i<=N; i++){
		who[srt[i].second] = i;
		arr[i] = srt[i].first;
	}
	for(int k = 0; k<2; k++){
		int s;
		cin >> s;
		while(s--){
			int n;
			cin >> n;
			n = who[n];
			msk[n] |= (1<<k);
		}
	}
	for(int i = 1; i<=N; i++){
		v[msk[i]].push_back(i);
		upd(i, 1);
	}	
	long long ans = LLONG_MAX/2, crnt = 0;
	for(int n : v[3]){
		pq.push(n);
		crnt += arr[n];
		upd(n, -1);
		S--;
		if((int) (pq.size()) == K){
			break;
		}
	}
	//cout << crnt << "\n";
	int Q = pq.size();
	int P = K - Q;
	/*
	for(int i = 1; i<=N; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i<=N; i++){
		cout << msk[i] << " ";
	}
	cout << "\n";
	cout << P << " " << Q << "\n";
	*/
	if((int) (v[1].size()) < P || (int) (v[2].size()) < P){
		cout << -1 << "\n";
		return 0;
	}
	for(int i = 0; i<P; i++){
		crnt += arr[v[1][i]];
		crnt += arr[v[2][i]];
		upd(v[1][i], -1);
		upd(v[2][i], -1);
		S -= 2;
	}
	//cout << crnt << "\n";
	if(M-Q-2*P >= 0 && S+Q+2*P >= M){
		//cout << clmb(M-Q-2*P) << "\n";
		ans = min(ans, crnt+clmb(M-Q-2*P));
	}
	while(pq.size()){
		Q--;
		int n = pq.top();
		pq.pop();
		crnt -= arr[n];
		upd(n, 1);
		S++;
		P++;
		if((int) (v[1].size()) < P || (int) (v[2].size()) < P){
			break;
		}
		crnt += arr[v[1][P-1]] + arr[v[2][P-1]];
		upd(v[1][P-1], -1);
		upd(v[2][P-1], -1);
		S -= 2;
		if(M-Q-2*P >= 0 && S+Q+2*P >= M){
			ans = min(ans, crnt+clmb(M-Q-2*P));
		}
	}
	if(ans >= LLONG_MAX/2){
		ans = -1;
	}
	cout << ans << "\n";
}