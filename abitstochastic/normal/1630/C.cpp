#include<bits/stdc++.h>
using namespace std;

int A[200003] , N; vector < int > pot[200003];

int main(){
	ios::sync_with_stdio(0); cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; pot[A[i]].push_back(i);}
	int pos = N , len = 0 , pre = N + 1;
	while(pos){
		int mn = pos - 1;
		for(int i = pos ; i < pre ; ++i) if(pot[A[i]].size()){mn = min(mn , pot[A[i]][0]); pot[A[i]].clear();}
		++len; pre = pos; pos = mn;
	}
	cout << N - len; return 0;
}