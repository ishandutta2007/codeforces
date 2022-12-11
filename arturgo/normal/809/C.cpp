#include <iostream>
#include <algorithm>
using namespace std;

int MOD = 1000 * 1000 * 1000 + 7;
long long SUP = (long long)1024 * 1024 * 1024;

int nbReqs;

long long ax, ay, bx, by, k;

long long getSomme(long long x = 0, long long y = 0, long long taille = SUP, long long deb = 0) {
	if(bx <= x || by <= y || x + taille <= ax || y + taille <= ay) {
		return 0;
	}
	if(ax <= x && x + taille <= bx) {
		long long tailleInter = min(by, y + taille) - max(ay, y);
		
		if(deb >= k)
			return 0;
		
		long long fin = min(deb + taille, k);
		
		long long totalTranche = (fin * (fin - 1) / 2 - deb * (deb - 1) / 2) % MOD;
		
		return (tailleInter * totalTranche + tailleInter * (fin -deb)) % MOD;
	}
	if(ay <= y && y + taille <= by) {
		long long tailleInter = min(bx, x + taille) - max(ax, x);
		
		if(deb >= k)
			return 0;
		
		long long fin = min(deb + taille, k);
		
		long long totalTranche = (fin * (fin - 1) / 2 - deb * (deb - 1) / 2) % MOD;
		
		return (tailleInter * totalTranche + tailleInter * (fin -deb)) % MOD;
	}
	
	
	return (
		getSomme(x, y, taille / 2, deb)
		+ getSomme(x + taille / 2, y, taille / 2, deb + taille / 2)
		+ getSomme(x, y + taille / 2, taille / 2, deb + taille / 2)
		+ getSomme(x + taille / 2, y + taille / 2, taille / 2, deb)
	) % MOD;
}

int main() {
	cin >> nbReqs;
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		cin >> ax >> ay >> bx >> by >> k;
		ax--;
		ay--;
		
		long long total = getSomme();
		
		cout << total % MOD << endl;
	}
	return 0;
}