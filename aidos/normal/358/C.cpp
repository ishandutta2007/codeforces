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
	int n, a, b[10];
	memset(b, 0, sizeof(b));
	string s[] = { "pushStack","pushQueue", "pushBack" }; 
	cin >> n;
	vector < int > v;
	for(int i = 0; i<n; i++){
		cin >> a;
		if(!a){
			memset(b, 0, sizeof(b));
			int k = 0, z = v.size(), l = 0;
			for(int j =1; j<z; j++)
				if(v[j]>v[l])l = j;
			for(int j = 0; j<z; j++){
				if(j == l){
					b[1] = v[j];
					cout << s[1] << "\n";
				}				
				else {
					int t = 0;
					if(b[t] > b[2]) t = 2;
					if(b[t] >= v[j]){
						cout << "pushFront\n";
					}
					else {
						b[t] = v[j];
						cout << s[t] << "\n";
					}
				}		
			}

			if(b[0]) k++;
			if(b[1]) k++;
			if(b[2]) k++;
			cout << k;
			if(b[0]) cout << " popStack";
			if(b[1]) cout << " popQueue";
			if(b[2]) cout << " popBack";
			cout << "\n";
			vector < int > rr;
			v = rr;
		}
		else {
			v.pb(a);
		}
	}
	int z = v.size();
	for(int i = 0; i<z; i++)
		cout << s[0] << "\n";
    return 0;
}