#include<bits/stdc++.h>
using namespace std;

string str; int N , M , pot[2000003] , Sum[2000003] , pot1[2000003] , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M >> str; for(int j = 0 ; j < N * M ; ++j) pot[j] = pot1[j] = 0;
		for(int i = 0 ; i < M ; ++i){int pos = i; while(pos < N * M && str[pos] == '0'){pos += M;} ++pot[pos];}
		Sum[0] = 0;
		for(int i = 0 ; i < N * M ; ++i){
			Sum[i] += str[i] == '1'; Sum[i + 1] = Sum[i];
		}
		for(int i = 0 ; i < N * M ; ++i) if(Sum[i] - (i < M ? 0 : Sum[i - M]) == 0) ++pot1[i];
		for(int i = 0 ; i < N * M ; ++i){
			pot[i + 1] += pot[i]; pot1[i + M] += pot1[i];
			cout << pot[i] - pot1[i] + i / M + 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}