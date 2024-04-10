#include<bits/stdc++.h>
using namespace std;

int A[200003] , N , T; string S;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 0 ; i < N ; ++i) cin >> A[i];
		cin >> S; vector < int > pr , pb;
		for(int i = 0 ; i < N ; ++i)(S[i] == 'B' ? pb : pr).push_back(A[i]);
		sort(pr.begin() , pr.end()); sort(pb.begin() , pb.end()); bool f = 1;
		for(int i = 0 ; i < pb.size() ; ++i) f &= pb[i] >= i + 1;
		int num = N; for(int i = (int)pr.size() - 1 ; i >= 0 ; --i) f &= pr[i] <= num--;
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}