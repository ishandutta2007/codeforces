#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> voisins[1000000];
vector<int> parents[1000000];

int curPasse = 0;
int derPasse[1000000];

void dfsParents(int noeud) {
	if(derPasse[noeud] == curPasse)
		return;
	derPasse[noeud] = curPasse;
	for(int voisin : parents[noeud]) {
		dfsParents(voisin);
	}
}

void dfsVoisins(int noeud) {
	if(derPasse[noeud] == curPasse)
		return;
	derPasse[noeud] = curPasse;
	for(int voisin : voisins[noeud]) {
		dfsVoisins(voisin);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	
	int nbTests;
	scanf("%d", &nbTests);

	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbMaisons, nbLiens;
		scanf("%d%d", &nbMaisons, &nbLiens);

		for(int iLien = 0;iLien < nbLiens;iLien++) {
			int a, b;
			scanf("%d%d", &a, &b);

			voisins[a - 1].push_back(b - 1);
			parents[b - 1].push_back(a - 1);
		}

		curPasse++;
		int melSommet = 0;
		for(int iMaison = 0;iMaison < nbMaisons;iMaison++) {
			if(derPasse[iMaison] != curPasse) {
				melSommet = iMaison;
				dfsParents(iMaison);
			}
		}

		curPasse++;
		dfsVoisins(melSommet);

		vector<int> jury, chats;

		for(int iMaison = 0;iMaison < nbMaisons;iMaison++) {
			if(derPasse[iMaison] == curPasse) {
				jury.push_back(iMaison);
			}
			else {
				chats.push_back(iMaison);
			}
		}

		if((int)jury.size() == nbMaisons) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			printf("%d %d\n", (int)jury.size(), (int)chats.size());
			for(int jur : jury) {
				printf("%d ", jur + 1);
			}
			printf("\n");
			for(int chat : chats) {
				printf("%d ", chat + 1);
			}
			printf("\n");
		}

		for(int iMaison = 0;iMaison < nbMaisons;iMaison++) {
			voisins[iMaison].clear();
			parents[iMaison].clear();
		}
	}

	return 0;
}