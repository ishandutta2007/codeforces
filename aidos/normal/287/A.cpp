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
	string s[10];
	for(int i = 0; i<4; i++){
		cin >> s[i];
	}
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			if(j<3 && s[i][j+1] == s[i+1][j] && s[i][j+1]==s[i+1][j+1]){
				cout << "YES";
				return 0;
			}
			if(j>0 && s[i][j-1] == s[i+1][j] && s[i][j-1]==s[i+1][j-1]){
				cout << "YES";
				return 0;
			}
		}
	}
	for(int i = 1; i<4; i++){
		for(int j = 0; j<4; j++){
			if(j<3 && s[i][j+1] == s[i-1][j] && s[i][j+1]==s[i-1][j+1]){
				cout << "YES";
				return 0;
			}
			if(j>0 && s[i][j-1] == s[i-1][j] && s[i][j-1]==s[i-1][j-1]){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}