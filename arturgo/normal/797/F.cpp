#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

const long long INFINI = (long long)50 * 1000 * 1000 * 1000 * 1000 * 1000;

long long dyn[2][6000];

pair<int, int> trous[6000];
int souris[6000];

int deb = 0, fin = 0;
pair<long long, long long> pfile[10000];

int main() {
	int nbSouris, nbTrous;
	scanf("%d%d", &nbSouris, &nbTrous);
	
	bool cur = false;
	for(int iSouris = 1;iSouris <= nbSouris;iSouris++) {
		scanf("%d", &souris[iSouris]);
		dyn[cur][iSouris] = INFINI;
	}

	for(int iTrou = 1;iTrou <= nbTrous;iTrou++) {
		scanf("%d%d", &trous[iTrou].first, &trous[iTrou].second);
	}
	
	sort(trous + 1, trous + nbTrous + 1);
	sort(souris + 1, souris + nbSouris + 1);
	
	for(int iTrou = 1;iTrou <= nbTrous;iTrou++) {
		cur = !cur;
		long long penal = 0;
		
		deb = fin = 0;
		
		pfile[fin++] = {0, 0};
		
		for(int iSouris = 1;iSouris <= nbSouris;iSouris++) {
			while(deb != fin && iSouris - pfile[deb].second > trous[iTrou].second) {
				deb++;
			}
			
			penal += abs(souris[iSouris] - trous[iTrou].first);
			
			while(deb != fin && pfile[fin - 1].first >= dyn[!cur][iSouris] - penal) {
				fin--;
			}
			
			pfile[fin++] = make_pair(dyn[!cur][iSouris] - penal, iSouris);
			
			dyn[cur][iSouris] = pfile[deb].first + penal;
		}
	}
	
	if(dyn[cur][nbSouris] < INFINI)
		cout << dyn[cur][nbSouris] << endl;
	else
		printf("-1\n");
	return 0;
}