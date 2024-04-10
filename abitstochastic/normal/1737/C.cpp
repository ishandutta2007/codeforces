#include<bits/stdc++.h>
using namespace std;

int T , L , R , N;
struct point{int x , y;}P1 , P2 , P3 , P4;
void input(point &P){cin >> P.x >> P.y;}
int sum(point P){return P.x + P.y;}
bool corner(point P){return (P.x == 1 || P.x == N) && (P.y == 1 || P.y == N);}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; input(P1); input(P2); input(P3); input(P4);
		int S = (sum(P1) + sum(P2) + sum(P3)) % 2;
		point A = sum(P1) % 2 == S ? P1 : (sum(P2) % 2 == S ? P2 : P3);
		bool flag = 1;
		if(corner(A)) flag = A.x == P4.x || A.y == P4.y;
		else if(sum(P4) % 2 != sum(A) % 2) flag = 1;
		else flag = (P4.x - A.x) % 2 == 0 && (P4.y - A.y) % 2 == 0;
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}