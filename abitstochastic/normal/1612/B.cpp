#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T , N , A , B;
	for(cin>>T;T;--T){
		cin>>N>>A>>B; vector < int > pl , pr;
		if(A - 1 > B || N - A + 1 - (B > A) < N / 2 || B - (A < B) < N / 2){cout << -1 << endl; continue;}
		for(int i = N ; i ; --i)
			if(i != B && i != A) (pl.size() < N / 2 - 1 ? pl : pr).push_back(i);
			else (i == B ? pr : pl).push_back(i);
		for(auto t : pl) cout << t << ' ';
		for(auto t : pr) cout << t << ' ';
		cout << endl;
	}
	return 0;
}