
// Problem : D. Discrete Centrifugal Jumps
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/contest/1407/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[400005];
int dist[400005];
int mxstk[400005], mxidx;
int mnstk[400005], mnidx;
vector<int> graph[400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		int mxlst = 0, mnlst = 0;
		while(mnidx && arr[mnstk[mnidx]] > arr[i]){
			if(mnlst != arr[mnstk[mnidx]]){
				graph[mnstk[mnidx]].emplace_back(i);
				mnlst = arr[mnstk[mnidx]];
			}
			mnidx--;
		}
		while(mxidx && arr[mxstk[mxidx]] < arr[i]){
			//cout << i << " " << mxlst << " " << mxstk[mxidx] << "\n";
			if(mxlst != arr[mxstk[mxidx]]){
				graph[mxstk[mxidx]].emplace_back(i);
				mxlst = arr[mxstk[mxidx]];
			}
			mxidx--;
		}
		if(mnidx && arr[mnstk[mnidx]] != mnlst){
			graph[mnstk[mnidx]].emplace_back(i);
		}
		if(mxidx && arr[mxstk[mxidx]] != mxlst){
			graph[mxstk[mxidx]].emplace_back(i);
		}
		mnstk[++mnidx] = (i);
		mxstk[++mxidx] = (i);
		dist[i] = INT_MAX/2;
	}
	dist[1] = 0;
	for(int i = 1; i<=N; i++){
		for(int e : graph[i]){
			//cout << i << " " << e << "\n";
			dist[e] = min(dist[e], dist[i] + 1);
		}
	}
	cout << dist[N] << "\n";
	
}