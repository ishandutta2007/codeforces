#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	int n;
	cin >> n;
	while(n){
		n--;
		string s[10];
		for(int i = 0; i<8; i++)
			cin >> s[i];
		vector < pii > v;
		for(int i = 0; i<8; i++)
			for(int j = 0; j<8; j++){
				if(s[i][j] == 'K'){
					v.pb(mp(i, j));
				}
			}
		int ok = 0, a[20][20], b[20][20];
		for(int i = 0; i<10; i++)
			for(int j = 0; j<10; j++)
				a[i][j] = b[i][j] = 0;
		queue < pii > q;
		q.push(v[0]);
		b[v[0].ff][v[0].sc] = 1;
		while(q.size()!=0){
			int x = q.front().ff, y = q.front().sc;
			q.pop();
			if(x >= 2){
				if(y>=2 && b[x-2][y-2] == 0){
					q.push(mp(x-2, y-2));
					b[x-2][y-2] = b[x][y] + 1;
				}
				if(y<6 && b[x-2][y+2] == 0){
					q.push(mp(x-2, y+2));
					b[x-2][y+2] = b[x][y]+1;
				}
			}
			if(x<6){
			 	if(y>=2 && b[x+2][y-2] == 0){
					q.push(mp(x+2, y-2));
					b[x+2][y-2] = b[x][y]+1;
				}
				if(y<6&& b[x+2][y+2] == 0 ){
					q.push(mp(x+2, y+2));
					b[x+2][y+2] = b[x][y]+1;
				}
			}
		}
		if((b[v[1].ff][v[1].sc]) % 2 == 1)cout << "YES\n";
		else cout<< "NO\n";
	}
    return 0;
}