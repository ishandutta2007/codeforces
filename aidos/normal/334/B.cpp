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
    int x[15], y[15];
    set < int > sx, sy;
    for(int i = 0; i<8; i++){
    	cin >> x[i] >> y[i];
    	sx.insert(x[i]);
    	sy.insert(y[i]);
	}
	if(sx.size() != 3 || sy.size() != 3) {
		cout << "ugly";
		return 0;
	}
	int z =0;
	for(set < int > :: iterator it1 = sx.begin();z < 3; it1++, z++){
		int k = 0;
		for(set < int > :: iterator it2 = sy.begin();k < 3; it2++, k++){
		if(z!= 1 || k!=1){
			bool ok = 0;
			for(int i = 0; i<8; i++)
				if(x[i] == *it1 && y[i] == *it2) {
					ok = 1;
				}
			if(!ok) {
				cout << "ugly";
				return 0;			
			}
		}
		else {
			bool ok = 0;
			for(int i = 0; i<8; i++)
				if(x[i] == *it1 && y[i] == *it2) {
					ok = 1;
				}
			if(ok) {
				cout << "ugly";
				return 0;			
			}
		}
		}
	}
	cout << "respectable";
    return 0;
}