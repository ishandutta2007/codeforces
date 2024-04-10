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
	string s;
	cin >> s;
	if(s[0] != '1'){
		cout << "NO";
	}
	else {
		for(int i=1; i<s.size(); i++){
			if(s[i] == '1') continue;
			if(s[i] != '4') {
				cout << "NO";
				return 0;
			}
			if(i>1 && s[i-1] == '4' && s[i-2] == '4') {
				cout << "NO";
				return 0;
			} 
		}
		cout << "YES";			
	}
    return 0;
}