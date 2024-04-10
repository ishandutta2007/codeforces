#include<bits/stdc++.h>
using namespace std;

int query(vector < int > pot){
	cout << "? " << pot.size();
	for(auto t : pot) cout << ' ' << t;
	cout << endl; fflush(stdout);
	string ans; cin >>ans;
	return ans == "YES";
}

void getans(int val){
	cout << "! " << val << endl; fflush(stdout);
	string str; cin >> str;
	if(str == ":)") exit(0);
}

vector < int > merge(vector < int > P , vector < int > Q){
	for(auto t : Q) P.push_back(t);
	return P;
}

signed main(){
	int N; cin >> N; vector < int > pot;
	for(int i = 1 ; i <= N ; ++i) pot.push_back(i);
	while(pot.size() > 2){
		vector < int > P[3];
		for(int i = 0 ; i < pot.size() ; ++i) P[i % 3].push_back(pot[i]);
		swap(P[0] , P[2]);
		int ans1 = query(P[0]);
		/*
		if(!ans1){
			int num = P[2].size() / 2;
			for(int i = 0 ; i < num ; ++i){P[1].push_back(P[2].back()); P[2].pop_back();}
		}
		int ans2 = query(P[1]);
		if(ans1 && ans2) pot = merge(P[0] , P[1]);
		if(ans1 && !ans2) pot = merge(P[0] , P[2]);
		if(!ans1 && ans2) pot = merge(P[1] , P[2]);
		if(!ans1 && !ans2){
			int ans3 = query(P[2]);
			if(ans3) pot = merge(P[0] , P[2]);
			else pot = P[1];
		}
		*/
		if(ans1){
			int ans2 = query(P[1]);
			if(ans2) pot = merge(P[0] , P[1]);
			if(!ans2) pot = merge(P[0] , P[2]);
		}else{
			int ans2 = query(merge(P[1] , P[2]));
			if(ans2) pot = merge(P[1] , P[2]);
			else{
				int ans3 = query(P[1]);
				if(ans3) pot = merge(P[0] , P[1]);
				else pot = merge(P[0] , P[2]);
			}
		}
	}
	for(auto t : pot) getans(t);
	assert(0);
	return 0;
}