#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 500;
bool mark[maxn];
vector <int> v;
int a[maxn];

int main (){
	int n;
	cin >> n;
	int pnt = n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mark[a[i]] = true;
		while (mark[pnt]){
			cout << pnt << " ";
			pnt --;
		}
		cout << endl;
	}
}