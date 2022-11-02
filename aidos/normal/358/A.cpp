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
	int n;
	cin >> n;
	int a[110000];
	for(int  i = 0; i<n; i++)
		cin  >> a[i];
	for(int i = 2; i<n; i++){
		for(int j = i-1; j>0; j--){
			if(a[i] < max(a[j-1], a[j]) && a[i] > min(a[j-1], a[j])){
				if(a[i-1] > max(a[j], a[j-1]) || a[i-1] < min(a[j], a[j-1])){
					cout << "yes";
					return 0;
				}
			}
			if(a[i-1] < max(a[j-1], a[j]) && a[i-1] > min(a[j-1], a[j])){
				if(a[i] > max(a[j], a[j-1]) || a[i] < min(a[j], a[j-1])){
					cout << "yes";
					return 0;
				}
			}
		}
	}
	cout << "no";
    return 0;
}