#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

int notes[6000];

int maxDpNote[200 * 1000];
int maxDpMod7[7];

int dp[6000][6000];

int main() {	
	int nbNotes;
	cin >> nbNotes;
	
	for(int iNote = 0;iNote < nbNotes;iNote++) {
		cin >> notes[iNote];
	}
	
	int valDep[6000];
	
	int maxDp = 0;
	for(int iMini = 0;iMini < nbNotes;iMini++) {
		valDep[iMini] = 1;
		for(int iMaxi = 0;iMaxi < iMini;iMaxi++) {
			if(abs(notes[iMaxi] - notes[iMini]) == 1 || (notes[iMaxi] - notes[iMini]) % 7 == 0) {
				valDep[iMini] = max(valDep[iMini], valDep[iMaxi] + 1);
			}
		}
		for(int iMaxi = 0;iMaxi < iMini;iMaxi++) {
			maxDpNote[notes[iMaxi]] = max(maxDpNote[notes[iMaxi]], 					dp[iMaxi][iMini]
			);
			maxDpMod7[notes[iMaxi] % 7] = max(maxDpMod7[notes[iMaxi] % 7], 					
				dp[iMaxi][iMini]
			);
		}
		
		for(int iMaxi = iMini + 1;iMaxi < nbNotes;iMaxi++) {
			dp[iMini][iMaxi] = valDep[iMini] + 1;
			dp[iMini][iMaxi] = max(dp[iMini][iMaxi], 
				maxDpMod7[notes[iMaxi] % 7] + 1
			);
			dp[iMini][iMaxi] = max(dp[iMini][iMaxi], 
				maxDpNote[notes[iMaxi] + 1] + 1
			);
			dp[iMini][iMaxi] = max(dp[iMini][iMaxi], 
				maxDpNote[notes[iMaxi] - 1] + 1
			);
			
			maxDp = max(maxDp, dp[iMini][iMaxi]);
			
			maxDpNote[notes[iMaxi]] = max(maxDpNote[notes[iMaxi]], 					dp[iMini][iMaxi]
			);
			maxDpMod7[notes[iMaxi] % 7] = max(maxDpMod7[notes[iMaxi] % 7], 					
				dp[iMini][iMaxi]
			);
		}
		
		for(int iNote = 0;iNote < nbNotes;iNote++) {
			maxDpNote[notes[iNote]] = 0;
		}
		
		for (int i = 0; i < 7; i += 1) {
			maxDpMod7[i] = 0;
		}
	}
	
	cout << maxDp << endl;
	return 0;
}