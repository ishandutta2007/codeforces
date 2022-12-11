#include <iostream>
#include <cstdio>
using namespace std;

int nbElems;
int vals[100001];

int dyn[300][100001];

int nbCoups(int pos, int cst) {
	if(pos > nbElems)
		return 0;
	if(dyn[cst][pos] == 0)
		dyn[cst][pos] = 1 + nbCoups(pos + vals[pos] + cst, cst);
	return dyn[cst][pos];
}

int main() {
	scanf("%d", &nbElems);
	
	for(int iElem = 1;iElem <= nbElems;iElem++) {
		scanf("%d", &vals[iElem]);
	}
	
	int nbReqs;
	cin >> nbReqs;
	
	int deb, cst;
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		scanf("%d%d", &deb, &cst);
		
		if(cst >= 300) {
			int nbTours = 0;
			while(deb <= nbElems) {
				deb = deb + vals[deb] + cst;
				nbTours++;
			}
		
			printf("%d\n", nbTours);
		}
		else {
			printf("%d\n", nbCoups(deb, cst));
		}
	}
	
	return 0;
}