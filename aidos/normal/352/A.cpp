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
	int n, k = 0, l = 0, a;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a;
		if(a) k++;
		else l++;
	}
	if(l<1){
		cout <<-1;
		return 0;
	}
	if(k<9){
		cout << 0;
		return 0;
	}
	int z = ((int)(k/9) )* 9;
	for(int i = 0; i<z; i++)
		cout << "5";
	for(int i = 0; i<l; i++)
		cout << "0";
    return 0;
}