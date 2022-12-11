#include <iostream>
#include <vector>
#include <bitset>
#define int long long
using namespace std;

const int MOD = 998244353;

int nbChaines;
vector<vector<int>> vecteurs;

int m(int x) {
	return (((x % MOD) + MOD) % MOD);
}

int val(vector<int> v) {
	int ret = 1;
	for(int x : v) ret = m((1 + x) * ret);
	return ret;
}

vector<int> v_min(vector<int> a, vector<int> b) {
	for(int i = 0;i < (int)a.size();i++) {
		a[i] = min(a[i], b[i]);
	}
	return a;
}

int inters[(1 << 23)];
vector<int> v_infini(26, MOD);

void explore(int iBit, int combi, vector<int> mini) {
	if(iBit == nbChaines) {
		inters[combi] = (__builtin_popcount(combi) % 2 ? 1 : -1) *val(mini);
		return;
	}
	
	explore(iBit + 1, combi, mini);
	explore(iBit + 1, combi | (1 << iBit), v_min(mini, vecteurs[iBit]));
}

signed main() {
	ios_base::sync_with_stdio(false);
	
	cin >> nbChaines;
	
	for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
		vector<int> vecteur(26, 0);
		string chaine;
		cin >> chaine;
		
		for(char car : chaine) {
			vecteur[car - 'a']++;
		}
		
		vecteurs.push_back(vecteur);
	}
	
	explore(0, 0, v_infini);
	inters[0] = 0;
	
	for(int iAxe = 0;iAxe < nbChaines;iAxe++) {
		for(int combi = 0;combi < (1 << nbChaines);combi++) {
			if((combi & (1 << iAxe)) == 0) {
				inters[combi | (1 << iAxe)] = m(inters[combi | (1 << iAxe)] + inters[combi]);
			}
		}
	}
	
	int v_finale = 0;
	for(int combi = 1;combi < (1 << nbChaines);combi++) {
		bitset<23> bits = combi;
		
		int facteur = 0;
		
		for(int bit = 0;bit < nbChaines;bit++) {
			if(bits[bit]) {
				facteur += bit + 1;
			}
		}
		
		v_finale ^= bits.count() * facteur * inters[combi];
	}
	
	cout << v_finale << endl;
	
	return 0;
}