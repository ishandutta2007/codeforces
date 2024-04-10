#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	srand(time(NULL));

	int nbExperts, nbRounds;
	cin >> nbExperts >> nbRounds;

	vector<int> gains(nbExperts, 0);

	int melScore = 0, monScore = 0;

	long double eta = sqrt(20 * log(nbExperts) / nbRounds);
	for(int iRound = 0;iRound < nbRounds;iRound++) {
		string chaine;
		cin >> chaine;

		long double sum1 = 0, sum0 = 0;
		long double somme = 0;
		for(int iExpert = 0;iExpert < nbExperts;iExpert++) {
			long double weight = expl(eta * (gains[iExpert] - melScore));
			somme += weight;

			if(chaine[iExpert] == '0') sum0 += weight;
			else sum1 += expl(eta * weight);
		}

		int maPred = 0;
		if(rand() / (long double)RAND_MAX <= sum0 / somme) {
			maPred = 0;
		}
		else {
			maPred = 1;
		}
		cout << maPred << endl << flush;

		int pred;
		cin >> pred;
		if(maPred == pred)
			monScore++;

		melScore = 0;
		for(int iExpert = 0;iExpert < nbExperts;iExpert++) {
			if(chaine[iExpert] == '0' + pred) {
				gains[iExpert]++;
				melScore = max(melScore, gains[iExpert]);
			}
		}
	}

	//cerr << melScore << " " << monScore << endl;
	return 0;
}