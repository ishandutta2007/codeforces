#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , L , R;
	for(cin >> T ; T ; --T){
		cin >> L >> R; int mx = 0 , S = R - L + 1; vector < pair < int , int > > lft;
		for(int i = 0 ; i < 20 ; ++i){
			int sum = L <= R ? ((R - L + 1) / 2 + ((L & 1) && (R & 1))) << i : 0;
			for(auto t : lft) sum += (t.first & 1) << t.second;
			mx = max(mx , sum);
			if(L <= R){
				if(L & 1){lft.push_back(make_pair(L , i)); ++L;}
				if(!(R & 1)){lft.push_back(make_pair(R , i)); --R;}
				L /= 2; R /= 2;
			}
			for(auto &t : lft) t.first >>= 1;
		}
		cout << S - mx << endl;
	}
	return 0;
}