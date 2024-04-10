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
	int n, x[410], a[410], u = 0, y = 0, t[410];
	bool b[410];
	for(int i = 0; i<305; i++){
		b[i]  = 0;
		a[i] = 0;
	}	
	cin >> n;
	n*=2;
	for(int i = 0; i < n ; i++)
		cin >> x[i];
	vector < int > v;
	for(int j = 0; j<n; j++)
		if(!b[j]){
			a[j] = 1;
			for(int i = j+1; i<n; i++)
				if(x[i]==x[j]){
					a[j]++;
					b[i] = 1;
				}
			if(a[j]==1) v.pb(j);	
		}
	int  h = v.size();
	for(int i = 0; i<h; i++)	
		if(u>=y){
			t[v[i]] = 1;
			y++;
		}
		else {
			t[v[i]] = 2;
			u++;
		}
	for(int i = 0; i<n; i++){
		if(a[i]>1){
			if(u>=y){
				t[i] = 1;
				y++;
			}
			else{
				t[i] =2;
				u++;
			}
			for(int j = i+1; j<n; j++){
				if(x[i]==x[j]){
					if(u>=y){
						y++;
						t[j] = 1;
					}
					else {
						u++;
						t[j] = 2;
					}
				}
			}
		}
	}
	set < int > s1, s2;
	for(int i = 0; i<n; i++){
		if(t[i] == 1){
			s1.insert(x[i]);
		}
		else s2.insert(x[i]);
	}
	cout << s1.size() * s2.size() << endl;
	for(int i = 0; i<n; i++)
		cout << t[i] << " ";
    return 0;
}