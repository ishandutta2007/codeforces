#include<bits/stdc++.h>
using namespace std;

int N , M , T; string S;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M >> S; int x = 0 , y = 0 , xmx = 0 , xmn = 0 , ymx = 0 , ymn = 0;
		for(int i = 0 ; i < S.size() ; ++i){
			switch(S[i]){
			case 'L': --y; break;
			case 'R': ++y; break;
			case 'D': ++x; break;
			case 'U': --x; break;
			}
			if(max(xmx , x) - min(xmn , x) == N || max(ymx , y) - min(ymn , y) == M) break;
			xmx = max(xmx , x); xmn = min(xmn , x); ymx = max(ymx , y); ymn = min(ymn , y);
		}
		cout << -xmn + 1 << ' ' << -ymn + 1 << endl;
	}
	return 0;
}