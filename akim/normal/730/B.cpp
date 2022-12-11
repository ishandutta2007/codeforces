#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;

int t;

vector <pii> v; 

char ques(int a,int b){
	cout << "? " << a << " " << b << endl;
	char ch;
	cin >> ch;
	return ch;
}

void print(int a,int b){
	cout << "! " << b << " "<< a << endl; 
}

void solve(int n){
	v.clear();
	if(n == 1){
		print(1,1);
		return;
	}
	if(n == 2){
		if(ques(1,2) == '>') print(1,2);
		else print(2,1); 
		return;
	}
	char ch;
	for(int i = 1; i < n; i += 2){
		if(ques(i,i + 1) == '>') v.pb(mp(i, i + 1));
		else v.pb(mp(i + 1, i));
	}
	if(n & 1) v.pb(mp(n,n));
	int cura = v[0].f, curb = v[0].s;
	for(int i = 1; i < v.size(); i++){
		if(ques(cura,v[i].f) == '<') cura = v[i].f;		
		if(ques(curb, v[i].s) == '>') curb = v[i].s;
	}
	print(cura, curb);
}

int main () {
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		solve(n);
	}
	

return 0;
}