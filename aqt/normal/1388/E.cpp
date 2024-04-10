
// Problem : E. Uncle Bogdan and Projections
// Contest : Codeforces - Codeforces Round #660 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1388/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int xl[2005], xr[2005], y[2005];
int srt[2005], srtl[2005], srtr[2005];
int idxl[2005], idxr[2005];

struct event{
	int typ;
	pair<int, int> vec;
	int idx1, idx2;
	bool operator < (const event e) const{
		long long v = 1LL*vec.first * e.vec.second - 1LL * vec.second * e.vec.first;
		if(!v){
			if(!typ && !e.typ){
				if(y[abs(idx2)] == y[abs(e.idx2)]){
					return y[abs(idx1)] > y[abs(e.idx1)];
				}
				return y[abs(idx2)] > y[abs(e.idx2)];
			}
			return typ < e.typ;
		}
		return v < 0;
	}
};
vector<event> pq;


long double proj(pair<long double, long double> pt, pair<long double, long double> v){
	return pt.first + -pt.second/v.second*v.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(14);
	cin >> N;
	bool sameheight = 1;
	for(int i = 1; i<=N; i++){
		cin >> xl[i] >> xr[i] >> y[i];
		if(i != 1 && y[i] != y[i-1]){
			sameheight = 0;
		}
		srt[i] = i;
	}
	if(sameheight){
		int mx = INT_MIN, mn = INT_MAX;
		for(int i = 1; i<=N; i++){
			mx = max(mx, xr[i]);
			mn = min(mn, xl[i]);
		}
		cout << mx - mn << "\n";
		return 0;
	}
	sort(srt+1, srt+1+N, [](int i, int j){
		if(y[i] == y[j]){
			return xl[i] < xl[j];
		}
		return y[i] < y[j];
	});
	for(int i = 1; i<=N; i++){
		srtl[i] = srtr[i] = srt[i];
		idxl[srtl[i]] = i;
		idxr[srtr[i]] = i;
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<i; j++){
			if(y[srt[i]] == y[srt[j]]){
				continue;
			}
			int h = y[srt[j]] - y[srt[i]];
			pq.push_back({-1, make_pair(xl[srt[j]] - xr[srt[i]], h)});
			pq.push_back({1, make_pair(xr[srt[j]] - xl[srt[i]], h)});
			pq.push_back({0, make_pair(xl[srt[j]] - xl[srt[i]], h), srt[j], srt[i]});
			pq.push_back({0, make_pair(xr[srt[j]] - xr[srt[i]], h), -srt[j], -srt[i]});
		}
	}
	int cnt = 0;
	long double ans = LLONG_MAX;
	sort(pq.begin(), pq.end());
	/*
	for(int i = 1; i<=N; i++){
		cout << srtl[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i<=N; i++){
		cout << srtr[i] << " ";
	}
	cout << "\n";	
	*/
	for(auto e : pq){
		//cout << e.vec.first << " " << e.vec.second << "\n";
		if(!cnt){
			//cout << proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) << " " << proj(make_pair(xl[srtl[1]], y[srtl[1]]), e.vec) << "\n";
		}		
		if(e.typ == 1){
			if(!cnt){
				ans = min(ans, proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) - proj(make_pair(xl[srtl[1]], y[srtl[1]]), e.vec));
			}
			//cout << proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) - proj(make_pair(xl[srtl[1]], y[srtl[1]]), e.vec) << "\n";
			cnt++;
		}
		else if(e.typ == -1){
			cnt--;
			if(!cnt){
				ans = min(ans, proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) - proj(make_pair(xl[srtl[1]], y[srtl[1]]), e.vec));				
			}
			//cout << "bing: " << srtr[N] << " " << proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) << "\n";		
		}
		else if(e.idx1 > 0){
			if(idxl[e.idx1] < idxl[e.idx2]){
				swap(srtl[idxl[e.idx1]], srtl[idxl[e.idx2]]);
				swap(idxl[e.idx1], idxl[e.idx2]);
			}
		}
		else{
			//cout << "swap: " << -e.idx1 << " " << -e.idx2 << "\n";
			if(idxr[-e.idx1] < idxr[-e.idx2]){
				swap(srtr[idxr[-e.idx1]], srtr[idxr[-e.idx2]]);
				swap(idxr[-e.idx1], idxr[-e.idx2]);
			}
		}
		if(!cnt){
			//cout << proj(make_pair(xr[srtr[N]], y[srtr[N]]), e.vec) << " " << proj(make_pair(xl[srtl[1]], y[srtl[1]]), e.vec) << "\n";
		}
		//cout << cnt << "\n";
	}
	/*
	for(int i = 1; i<=N; i++){
		cout << srtl[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i<=N; i++){
		cout << srtr[i] << " ";
	}
	cout << "\n";
	*/
	cout << ans;
}