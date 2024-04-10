#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair < int , int >
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
string str[300003]; int N , M , p , q;
int id(int x , int y){return x * M + y;}
vector < int > fir; vector < pii > nxt[300003]; int dis[300003] , pre[300003];
void add(int x , int y , int w){nxt[x].push_back(pii(y , w));}

int check(int x , int y){return x >= 0 && x < N && y >= 0 && y < M && str[x][y] != '#';}

signed main(){
	cin >> N >> M >> p >> q;
	for(int i = 0 ; i < N ; ++i) cin >> str[i];
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < M ; ++j)
			if(str[i][j] == '.') fir.push_back(id(i , j));
			else if(str[i][j] == 'L'){
				bool flg = 0;
				if(check(i - 1 , j + 1)){
					add(id(i - 1 , j + 1) , id(i , j) , p); flg |= str[i - 1][j + 1] == '.';
				}
				if(check(i + 1 , j + 1)){
					add(id(i + 1 , j + 1) , id(i , j) , p); flg |= str[i + 1][j + 1] == '.';
				}
				if(check(i , j + 2)) add(id(i , j + 2) , id(i , j) , min(q , flg ? 2 * p : (int)2e9));
			}else if(str[i][j] == 'R'){
				bool flg = 0;
				if(check(i - 1 , j - 1)){
					add(id(i - 1 , j - 1) , id(i , j) , p); flg |= str[i - 1][j - 1] == '.';
				}
				if(check(i + 1 , j - 1)){
					add(id(i + 1 , j - 1) , id(i , j) , p); flg |= str[i + 1][j - 1] == '.';
				}
				if(check(i , j - 2)) add(id(i , j - 2) , id(i , j) , min(q , flg ? 2 * p : (int)2e9));
			}else if(str[i][j] == 'U'){
				bool flg = 0;
				if(check(i + 1 , j + 1)){
					add(id(i + 1 , j + 1) , id(i , j) , p); flg |= str[i + 1][j + 1] == '.';
				}
				if(check(i + 1 , j - 1)){
					add(id(i + 1 , j - 1) , id(i , j) , p); flg |= str[i + 1][j - 1] == '.';
				}
				if(check(i + 2 , j)) add(id(i + 2 , j) , id(i , j) , min(q , flg ? 2 * p : (int)2e9));
			}else if(str[i][j] == 'D'){
				bool flg = 0;
				if(check(i - 1 , j + 1)){
					add(id(i - 1 , j + 1) , id(i , j) , p); flg |= str[i - 1][j + 1] == '.';
				}
				if(check(i - 1 , j - 1)){
					add(id(i - 1 , j - 1) , id(i , j) , p); flg |= str[i - 1][j - 1] == '.';
				}
				if(check(i - 2 , j)) add(id(i - 2 , j) , id(i , j) , min(q , flg ? 2 * p : (int)2e9));
			}
	priority_queue < pii > q; memset(dis , 0x3f , sizeof(dis));
	for(auto t : fir){pre[t] = t; q.push(pii(0 , t)); dis[t] = 0;}
	while(!q.empty()){
		int t = q.top().second;
		if(dis[t] != -q.top().first){q.pop(); continue;}
		q.pop();
		for(auto p : nxt[t])
			if(dis[p.first] > dis[t] + p.second){
				dis[p.first] = dis[t] + p.second; pre[p.first] = pre[t];
				q.push(pii(-dis[p.first] , p.first));
			}
	}
	int ans = 1e18;
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < M ; ++j)
			if(check(i , j)){
				if(check(i , j + 1) && str[i][j] != 'L' && pre[id(i,j)] != pre[id(i,j + 1)])
					ans = min(ans , dis[id(i , j)] + dis[id(i , j + 1)]);
				if(check(i + 1 , j) && str[i][j] != 'U' && pre[id(i,j)] != pre[id(i + 1,j)])
					ans = min(ans , dis[id(i , j)] + dis[id(i + 1 , j)]);
			}
	cout << (ans > 1e16 ? -1 : ans) << endl;
}