#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int nbElements, nbRequetes;

int vals[200 * 1000];

int mini[(1 << 19)];
int maxi[(1 << 19)];

int maX(int a, int b) {
	if(a == -1)
		return b;
	if(b == -1)
		return a;
	if(vals[a] > vals[b])
		return a;
	return b;
}

int miN(int a, int b) {
	if(a == -1)
		return b;
	if(b == -1)
		return a;
	if(vals[a] < vals[b])
		return a;
	return b;
}

void setMax(int pos, int val) {
	pos += (1 << 18);
	
	while(pos != 0) {
		maxi[pos] = maX(val, maxi[pos]);
		pos /= 2;
	}
}

void setMin(int pos, int val) {
	pos += (1 << 18);
	
	while(pos != 0) {
		mini[pos] = miN(val, mini[pos]);
		pos /= 2;
	}
}

int getMin(int debut, int fin) {
	debut += (1 << 18);
	fin += (1 << 18);
	
	int minI = mini[debut];
	while(debut < fin) {
		if(debut % 2 == 1) {
			minI = miN(minI, mini[debut]);
			debut++;
		}
		if(fin % 2 == 1) {
			fin--;
			minI = miN(minI, mini[fin]);
		}
		debut /= 2;
		fin /= 2;
	}
	
	return minI;
}

int getMax(int debut, int fin) {
	debut += (1 << 18);
	fin += (1 << 18);
	
	int maxI = maxi[debut];
	while(debut < fin) {
		if(debut % 2 == 1) {
			maxI = maX(maxI, maxi[debut]);
			debut++;
		}
		if(fin % 2 == 1) {
			fin--;
			maxI = maX(maxI, maxi[fin]);
		}
		debut /= 2;
		fin /= 2;
	}
	
	return maxI;
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	scanf("%d%d", &nbElements, &nbRequetes);
	
	fill(mini, mini + (1 << 19), -1);
	fill(maxi, maxi + (1 << 19), -1);
	
	for(int iElem = 0;iElem < nbElements;iElem++) {
		int val;
		scanf("%d", &val);
		vals[iElem] = val;
		setMax(iElem, iElem);
		setMin(iElem, iElem);
	}
	
	for(int iR = 0;iR < nbRequetes;iR++) {
		int debut, fin, x;
		scanf("%d%d%d", &debut, &fin, &x);
		
		int m = getMin(debut - 1, fin);
		int M = getMax(debut - 1, fin);
		
		if(vals[m] != x)
			printf("%d\n", m + 1);
		else if(vals[M] != x)
			printf("%d\n", M + 1);
		else
			printf("-1\n");
	}
	return 0;
}