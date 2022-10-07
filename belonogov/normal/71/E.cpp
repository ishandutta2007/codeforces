#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxAlf = 100 + 2;
const int MAXN = 18;
const int inf = 1e9;
const string Name[101] = {"-1", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};


map < string, int > q;
int a[maxAlf];
int b[maxAlf];
string s;
vector < int > e[MAXN];
bool dp[MAXN][1 << MAXN];
int p[MAXN][1 << MAXN];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, sum;
	int mask, mask_step;
	for (int i = 1; i <= 100; i++)
		q[Name[i]] = i;
	scanf("%d%d", &n, &m);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++){
		cin >> s;
// 		cerr << "s " << s << endl;
		a[i] = q[s];		
		sum1 += a[i];			
	}
	for (int i = 0; i < m; i++){
		cin >> s;
// 		cerr << "s " << s << endl;
		b[i] = q[s];
		sum2 += b[i];
	}
	for (int mask = 0; mask < (1 << n); mask++){
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += (mask & (1 << i))? a[i] : 0;
		for (int i = 0; i < m; i++)
			if (sum == b[i])
				e[i].pb(mask);
	}
	dp[0][0] = 1;
	for (int i = 0; i < m; i++)
		for (int mask = 0; mask < (1 << n); mask++){
			if (dp[i][mask] == 0)
				continue;
			for (int j = 0; j < (int)e[i].size(); j++)
				if ((e[i][j] & mask) == 0){
					dp[i + 1][mask | e[i][j]] = 1;
					p[i + 1][mask | e[i][j]] = e[i][j];
				}
		}
	if (dp[m][(1 << n) - 1]){
		printf("YES\n");
		mask = (1 << n) - 1;
		for (int j = m; j > 0; j--){
			mask_step = p[j][mask];
			//cerr << "mask_step " << mask_step << endl;
			bool first = 1;
			for (int i = 0; i < n; i++)		
				if (mask_step & (1 << i)){
					if (!first)
						cout << "+";
					first = 0;
					cout << Name[a[i]];
				}
			cout << "->";
			cout << Name[b[j - 1]] << "\n";
			mask = mask ^ mask_step;
		}
	}
	else
		printf("NO\n");

	
	
    return 0;
}