#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define mp make_pair
#define pb push_back
#define pp push
using namespace std;
int  d[110][110], n, t;
queue < pair <int, int> > q;
bool m[110][110];
void dfs(int x, int z){
m[x][z] = 0;
	if(x>0&& d[x-1][z] && m[x-1][z]) dfs(x-1, z);
	if(z>0 && d[x][z-1] && m[x][z-1]) dfs(x, z-1);
	if(x<n-1 && d[x+1][z] && m[x+1][z]) dfs(x+1, z);
	if(z<t-1 && d[x][z+1] && m[x][z+1]) dfs(x, z+1);  	
}
int main () {   
char c;
cin >> n >> t;
int x, y;
for(int i=0; i<n; i++)
	for(int j=0; j<t; j++){
		cin >> c;
		if(c=='B') {
			d[i][j] = 1;
			q.pp(mp(i, j));
		}
		else {
			d[i][j] = 0;
		}
		m[i][j] = 1;
	}
if(!q.empty()){
	dfs(q.front().first, q.front().second);
}
else  {
	cout << "YES";
	return 0;
}
for(int i=0; i<n; i++){
	for(int j=0; j<t; j++){
		for(int k=0; k<=i; k++){
			for(int g=0; g<t; g++){
				if(d[i][j] && d[k][g] &&d[i][g]==0 && d[k][j]==0){
					cout << "NO";
					return 0;
				}
			}
		}
	}
}
while(!q.empty()){
	x = q.front().first;
	y = q.front().second;
	if(m[x][y]==1){
		cout << "NO";
		return 0;
	}
	if(x<n-1 && d[x+1][y]!=1){
		for(int i=x+2; i<n; i++)
			if(d[i][y]==1){
				cout << "NO";
				return 0;	
			}		
	}
	if(y<t-1 && d[x][y+1]!=1){
		for(int i=y+2; i<t; i++)
			if(d[x][i]==1){
				cout << "NO";
				return 0;	
			}		
	}
	q.pop();
}

cout << "YES";
return 0;
}