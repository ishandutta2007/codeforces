#include <cstdio>
#include <vector>
using namespace std;

vector<int> voisins[1000 * 1000];
int parents[1000 * 1000];
bool estNoir[1000 * 1000];

int minLocal[1000 * 1000];
int minGlobal = 1000 * 1000;


int nbNoeuds, nbReqs;

void enracine(int noeud, int mini = 1000 * 1000, int parent = -1) {
	parents[noeud] = parent;
	
	mini = min(mini, noeud);
	minLocal[noeud] = mini;
	
	for(int v : voisins[noeud]) {
		if(v != parent)
			enracine(v, mini, noeud);
	}
}

int main() {
	scanf("%d%d", &nbNoeuds, &nbReqs);
	
	for(int iNoeud = 0;iNoeud < nbNoeuds - 1;iNoeud++) {
		int deb, fin;
		scanf("%d%d", &deb, &fin);
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	int type, arg;
	scanf("%d%d", &type, &arg);
	
	enracine(arg);
	estNoir[arg] = true;
	minGlobal = arg;
	
	int last = 0;
	for(int iReq = 0;iReq < nbReqs - 1;iReq++) {
		scanf("%d%d", &type, &arg);
		
		if(type == 1) {
			int pos = (arg + last) % nbNoeuds;
			
			while(!estNoir[pos]) {
				estNoir[pos] = true;
				minGlobal = min(minGlobal, pos);
				pos = parents[pos];
			}
		}
		else {
			int pos = (arg + last) % nbNoeuds;
			last = min(minLocal[pos], minGlobal) + 1;
			printf("%d\n", last);
		}
	}
	
	return 0;
}