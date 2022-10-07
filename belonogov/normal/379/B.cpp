#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1000;
const int inf = 1e9;

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool flag = 1;
	while (flag){
		flag = 0;
		for (int i = 0; i < n; i++){
			if (a[i]){
				printf("P");
				a[i]--;
				flag = 1;				
			}
			if (i + 1 != n)
				printf("R");			
		}
		for (int i = 0; i < n - 1; i++)
			printf("L");
	}
	printf("\n");
	
    return 0;
}