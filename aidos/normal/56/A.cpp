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
#define pss pair<string, string>
using namespace std;
string s[] ={
	"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"
};
int main () {
	int n, k = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		string t;
		cin >> t;
		if(t[0] >= 'A' && t[0] <='Z'){
			for(int j = 0; j<11; j++)
				if(s[j] == t) k++;
		}
		else {
			int x=t.size(), u = 0;
			for(int i = 0; i<x; i++)
				u = u*10 + t[i] - '0';
			if(u<18) k++;
		}
	}
	cout << k;
	return 0;
}