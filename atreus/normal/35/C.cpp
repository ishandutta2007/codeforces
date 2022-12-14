#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 4e6 + 500;
int x[20], y[20];

int main (){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, k;
	fin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		fin >> x[i] >> y[i];
	int idx, idy, ans = -1;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			int dis = maxn;
			for (int l = 0; l < k; l++)
				dis = min (dis, abs(i - y[l]) + abs(j - x[l]));
			if (ans < dis){
				ans = dis;
				idx = i;
				idy = j;
			}
		}
	}
	fout << idy << " " << idx << endl;
}