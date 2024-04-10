#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <bitset>
using namespace std;

set<int> primes;
set<int> total;

const int NB_VECTS = 64;
vector<vector<bool>> hashs;

bitset<NB_VECTS> cur_hash(0);

void revert(int x, set<int>& s) {
	for(int iVect = 0;iVect < NB_VECTS;iVect++) {
		cur_hash[iVect] = cur_hash[iVect] ^ hashs[iVect][x];
	}
}

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	for(int iVect = 0;iVect < NB_VECTS;iVect++) {
		hashs.push_back(vector<bool>());
		for(int iFois = 0;iFois <= nbNombres;iFois++) {
			hashs.back().push_back(rand() % 2);
		}
	}
	
	unordered_map<bitset<NB_VECTS>, int> hashs;
	
	bitset<NB_VECTS> hash_total;
	for(int iNombre = 1;iNombre <= nbNombres;iNombre++) {
		int n = iNombre;
		
		for(int k = 2;k * k <= n;k++) {
			while(n % k == 0) {
				n /= k;
				revert(k, primes);
			}
		}
		
		if(n != 1) {
			revert(n, primes);
		}
		
		hashs[cur_hash] = iNombre;
		hash_total = hash_total ^ cur_hash;	
	}
	
	if(hash_total == bitset<NB_VECTS>(0)) {
		cout << nbNombres << endl;
		
		for(int i = 1;i <= nbNombres;i++) {
			cout << i << " ";
		}
		cout << endl;
		
		return 0;
	}
	
	if(hashs.count(hash_total)) {
		cout << nbNombres - 1 << endl;
		
		int manque = hashs[hash_total];
		for(int i = 1;i <= nbNombres;i++) {
			if(i != manque)
				cout << i << " ";
		}
		cout << endl;
		
		return 0;
	}
	
	for(pair<bitset<NB_VECTS>, int> hash : hashs) {
		int manque1 = hash.second;
		bitset<NB_VECTS> nouv_hash = hash.first ^ hash_total;
		
		if(hashs.count(nouv_hash)) {
			cout << nbNombres - 2 << endl;
			
			int manque2 = hashs[nouv_hash];
			for(int i = 1;i <= nbNombres;i++) {
				if(i != manque1 && i != manque2)
					cout << i << " ";
			}
			cout << endl;
			
			return 0;
		}
	}
	
	hash_total = hash_total ^ cur_hash;
	
	for(pair<bitset<NB_VECTS>, int> hash : hashs) {
		int manque1 = hash.second;
		bitset<NB_VECTS> nouv_hash = hash.first ^ hash_total;
		
		if(hashs.count(nouv_hash)) {
			cout << nbNombres - 3 << endl;
			
			int manque2 = hashs[nouv_hash];
			for(int i = 1;i <= nbNombres;i++) {
				if(i != manque1 && i != manque2 && i != nbNombres)
					cout << i << " ";
			}
			cout << endl;
			
			return 0;
		}
	}
	
	return 0;
}