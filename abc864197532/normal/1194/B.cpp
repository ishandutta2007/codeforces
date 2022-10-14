#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;

int row[50000],col[50000];
int n,m;

int main () {
	int t,a,i,j;
	char q;
	cin >> t;
	for (a=0;a<t;++a) {
		cin >> n >> m;
		int nums[n][m];
		for (i=0;i<n;++i) row[i]=0;
		for (i=0;i<m;++i) col[i]=0;
		for (i=0;i<n;++i) {
			for (j=0;j<m;++j) {
				nums[i][j]=0;
				cin >> q;
				if (q=='.') {
					row[i]++;
					col[j]++;
					nums[i][j]=1;
				}
			}
		}
		int max=100000,q;
		for (i=0;i<n;++i) {
			for (j=0;j<m;++j) {
				q=row[i]+col[j]-nums[i][j];
				if (max>q) max=q;
			}
		}
		cout << max << endl;
	}
}