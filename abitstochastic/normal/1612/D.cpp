#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	long long T , A , B , X;
	for(cin >> T ; T ; --T){
		cin >> A >> B >> X; bool flg = 0;
		do{
			if(A == X || B == X){flg = 1; break;}
			if(A > B) swap(A , B);
			long long T = B % A;
			if(X < B && X >= T && (X - T) % A == 0){flg = 1; break;}
			B = T;
		}while(A && B);
		cout << (flg ? "YES\n" : "NO\n");
	}
	return 0;
}