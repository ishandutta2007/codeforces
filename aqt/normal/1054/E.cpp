
// Problem : E. Chips Puzzle
// Contest : Codeforces - Mail.Ru Cup 2018 Round 1
// URL : https://codeforces.com/contest/1054/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
deque<char> dq[305][305];
string fin[305][305];
vector<pair<pair<int, int>, pair<int, int>>> ans;

void move(int x, int y, int a, int b){
	ans.push_back(make_pair(make_pair(x, y), make_pair(a, b)));
	dq[a][b].push_back(dq[x][y].front());
	dq[x][y].pop_front();
}

void out(){
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			for(char c : dq[i][j]){
				cout << c;
			}
			cout << " ";
		}
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			string s;
			cin >> s;
			reverse(s.begin(), s.end());
			for(char c : s){
				dq[i][j].push_back(c);
			}
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> fin[i][j];
			reverse(fin[i][j].begin(), fin[i][j].end());
		}
	}
	for(int i = 2; i<=N; i++){
		for(int j = 3; j<=M; j++){
			while(dq[i][j].size()){
				move(i, j, 1, j);
			}
		}
	}
	int sz11 = dq[1][1].size(), sz12 = dq[1][2].size();
	while(sz11--){
		if(dq[1][1].front() == '0'){
			move(1, 1, 2, 1);
		}
		else{
			move(1, 1, 1, 2);
		}
	}
	while(sz12--){
		if(dq[1][2].front() == '1'){
			move(1, 2, 2, 2);
		}
		else{
			move(1, 2, 1, 1);
		}
	}
	for(int i = 2; i<=N; i++){
		while(dq[i][1].size()){
			if(dq[i][1].front() == '0'){
				move(i, 1, 1, 1);
			}
			else{
				move(i, 1, i, 2);
			}
		}
		while(dq[i][2].size()){
			if(dq[i][2].front() == '0'){
				move(i, 2, i, 1);
			}
			else{
				move(i, 2, 1, 2);
			}
		}
		while(dq[i][1].size()){
			move(i, 1, 1, 1);
		}
	}
	for(int j = 3; j<=M; j++){
		while(dq[1][j].size()){
			if(dq[1][j].front() == '0'){
				move(1, j, 1, 1);
			}
			else{
				move(1, j, 1, 2);
			}
		}
	}
	//out();
	for(char c : fin[1][1]){
		if(c == '0'){
			move(1, 1, 2, 1);
			move(2, 1, 1, 1);
		}
		else{
			move(1, 2, 1, 1);
		}
	}
	for(char c : fin[1][2]){
		if(c == '0'){
			move(1, 1, 1, 2);
		}
		else{
			move(1, 2, 2, 2);
			move(2, 2, 1, 2);
		}
	}
	for(int i = 2; i<=N; i++){
		for(int j = 3; j<=M; j++){
			for(char c : fin[i][j]){
				if(c == '0'){
					move(1, 1, 1, j);
					move(1, j, i, j);
				}
				else{
					move(1, 2, 1, j);
					move(1, j, i, j);
				}
			}
		}
	}
	for(int j = 3; j<=M; j++){
		for(char c : fin[1][j]){
			if(c == '0'){
				move(1, 1, 1, j);
			}
			else{
				move(1, 2, 1, j);
			}
		}
	}
	for(int i = 2; i<=N; i++){
		for(char c : fin[i][2]){
			if(c == '0'){
				move(1, 1, i, 1);
			}
		}
		for(char c : fin[i][1]){
			if(c == '1'){
				move(1, 2, i, 2);
			}
		}
		for(char c : fin[i][2]){
			if(c == '0'){
				move(i, 1, i, 2);
			}
			else{
				move(1, 2, i, 2);
			}
		}
		for(char c : fin[i][1]){
			if(c == '0'){
				move(1, 1, i, 1);
			}
			else{
				move(i, 2, i, 1);
			}
		}
	}
	//out();
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << "\n";
	}
}