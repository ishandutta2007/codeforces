#include<bits/stdc++.h>
using namespace std;

#define int long long
int C , N; string S , T; vector < int > pot[26];
#define lowbit(x) ((x) & -(x))
int arr[100003];
void add(int x , int v){++x; while(x <= N){arr[x] += v; x += lowbit(x);}}
int qry(int x){++x; int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}

signed main(){
	for(cin >> C ; C ; --C){
		cin >> N >> S >> T; string R = S; sort(R.begin() , R.end());
		if(R >= T){cout << -1 << endl; continue;}
		for(int i = 0 ; i < 26 ; ++i) pot[i].clear();
		for(int i = S.size() - 1 ; ~i ; --i) pot[S[i] - 'a'].push_back(i);
		int mn = 1e18 , cur = 0; memset(arr , 0 , sizeof(int) * (N + 1));
		for(int i = 0 ; i < N ; ++i){
			int V = T[i] - 'a';
			for(int j = 0 ; j < V ; ++j)
				if(pot[j].size()) mn = min(mn , cur + pot[j].back() - qry(pot[j].back()));
			if(pot[V].size()){int t = pot[V].back(); cur += t - qry(t); add(t , 1); pot[V].pop_back();}
			else break;
		}
		cout << mn << endl;
	}
	return 0;
}