#include<bits/stdc++.h>
using namespace std;

const int _ = 4e6 + 7; int N , M , T , val[2003][2003] , id[2003][2003] , cnt , prex , prey; char Map[2003][2003]; bool ins[2003][2003];
int search(int p , int q){
	vector < pair < int , int > > pot; pot.push_back(make_pair(p , q)); int preval = 0; int pp = p , qq = q;
	while(1){
		p = pot.back().first; q = pot.back().second;
		if(p < 0 || q < 0 || p >= N || q >= M){preval = 0; break;}
		if(ins[p][q]){preval = -1; break;} if(~val[p][q]){preval = val[p][q]; break;}
		ins[p][q] = 1; int t = p , r = q; id[p][q] = ++cnt;
		switch(Map[p][q]){
		case 'L': --r; break;
		case 'R': ++r; break;
		case 'U': --t; break;
		case 'D': ++t; break;
		}
		pot.push_back(make_pair(t , r));
	}
	for(int i = (int)pot.size() - 2 ; ~i ; --i){
		p = pot[i].first; q = pot[i].second; int t = pot[i + 1].first , r = pot[i + 1].second , V = preval; ins[p][q] = 0;
		if(V == -1){val[p][q] = id[p][q] - id[prex = t][prey = r] + 1; preval = -val[p][q];}
		else if(V < 0){val[p][q] = -V; preval = p == prex && q == prey ? val[p][q] : V;}
		else preval = val[p][q] = V + 1;
	}
	return val[pp][qq];
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 0 ; i < N ; ++i) for(int j = 0 ; j < M ; ++j){cin >> Map[i][j]; val[i][j] = -1;}
		int mx = 0 , mxi = 0 , mxj = 0;
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < M ; ++j){
				int t = search(i , j); if(mx < t){mx = t; mxi = i; mxj = j;}
			}
		cout << mxi + 1 << ' ' << mxj + 1 << ' ' << mx << endl;
	}
	return 0;
}